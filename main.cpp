#include <iostream> 
#include <cstring>
#include "Car.h"
#include "Bike.h"
 
/* C++에서의 파일 분할
   대부분의 프로그램은 하나의 파일에 모든걸 담지 않음.
   특히 c++과 같은 객체지향 언어는 더함.
   
   c++은 클래스 별로 헤더파일과 소스파일을 생성해서
   클래스의 선언과 정의를 분리하는 경우가 많다고 함.
   많은 수의 파일이 만들어짐
*/

#define PI 3.141592
// #define CU(x) ((x)*(x)*(x))

inline int CU(int x){
    return x*x*x;
}

namespace A { void Add() { printf("A의 Add() 호출 \n");}}
namespace B { void Add() { printf("B의 Add() 호출 \n");}}

namespace u4bi{ void good(){ printf("u4bi c++ \n"); } }
namespace github{
    void win(){ printf("github win\n");}
    void lose(){ printf("github lose\n");}
}

using namespace u4bi;
using github::win;

using namespace std;

class Rectangle{
private :
    int width;
    int height;
public:
    explicit Rectangle(int width=0, int height = 0) : width(width), height(height){}
    int area(){ return width * height; }
    /*  위 area() 함수의 반환형은 int이며 매개변수의 타입은 int, int 임
        area()함수는 Rectangle 클래스의 멤버 함수 */
};

template <typename T>
class Data{
private: T data;
public:
    Data(T data) : data(data){}
        void show(){
        cout << data << endl;
    }
};

template<typename T>
   void template_Swap(T& num_a, T& num_b){
    T temp = num_a;
    num_a = num_b;
    num_b = temp;
}

class NumBox{
private:
    int num_a, num_b;
public:
    NumBox(int num_a, int num_b) : num_a(num_a), num_b(num_b){}
    void show(){
        cout << "num_a : " << num_a << " num_b : " << num_b << endl;
    }
    NumBox operator+(NumBox &ref){
        return NumBox(num_a+ref.num_a, num_b+ref.num_b);
    }
};

class ParentOne{ public : void funcOne(){ cout << "funcOne() 호출 " << endl; } };
class ParentTwo{ public : void funcTwo(){ cout << "funcTwo() 호출 " << endl; } };
class multipleInheritance_Child : public ParentOne, public ParentTwo{
public :
    void func() {
        funcOne();
        funcTwo();
    }
};

class pure_virtual_Parent{
public : virtual void func() = 0;
};
class pure_virtual_Child : public pure_virtual_Parent {
public : virtual void func(){ cout << "pure-virtual : 자식 클래스의 func 함수 호출 " << endl; }
};

class virtual_Parent{
public: virtual void func(){ cout << " 부모 클래스 func() 호출 " << endl; }
};
class virtual_Child : public virtual_Parent{
    public: virtual void func(){ cout << " 자식 클래스 func() 호출 " << endl; }
};

class overriding_A{
public: void over(){ cout << " A 클래스의 over 함수 호출 " << endl; }
};
class overriding_B : public overriding_A {
public:
    void over(){
        overriding_A::over();
        cout << " B 클래스의 over 함수 호출 " << endl;
    }
};

class thisPointer{
private:
    int age;
public:
    thisPointer(int age){
        age = age;
    }
};

class ThisPointExample{
private:
    int num_a;
    int num_b;
public:
    ThisPointExample(int num_a, int num_b){
        this->num_a = num_a;
        this->num_b = num_b;
    }
    void getInfo(){
        cout << "num a : " << num_a << endl;
        cout << "num_b : " << num_b << endl;
    }
};

class ItemEX{
private:
    int id;
    char name[10];
    int price;
public:
    ItemEX(int _id, char *_name, int _price) : id(_id), price(_price) { strcpy(name, _name); }
    void getInfo(){
        cout << "번호 : " << id << endl;
        cout << "물품 : " << name << endl;
        cout << "가격 : " << price << endl;
    }
};

class Item{
private:
    int id;
    char name[10];
    int price;
public:
    Item(){ cout << "생성자 호출 " << endl; }
    void setInfo(int _id, char *_name, int _price){
        id = _id;
        strcpy(name, _name);
        price = _price;
    }
    void getInfo(){
        cout << "번호 : " << id << endl;
        cout << "물품 : " << name << endl;
        cout << "가격 : " << price << endl;
    }
    ~Item(){ cout << "소멸자 호출 " << endl; }
};

class Parent{
private : int num_a;
protected : int num_b;
public : int num_c;
};
class Base_Private : private Parent{};
class Base_Protected : protected Parent{};
class Base_Public : public Parent{};
 
class memInit{
private:
    int num_a;
    int num_b;
public:
    memInit(int _num_a, int _num_b) : num_a(_num_a), num_b(_num_b){}
    void show(){
        cout << "num a : " << num_a << " num b : " << num_b << endl;
    }
};

class Human{
private:
    int age;
    char name[10];
    char hobby[20];
public:
    Human(int _age, char *_name, char *_hobby) : age(_age){
        strcpy(name, _name);
        strcpy(hobby, _hobby);
    }
    void getup(){ cout << "기상!" << endl; }
    void sleep(){ cout << "취침!" << endl; }
    void eat(){ cout << "식사!" << endl; }
    void study(){ cout << "공부!" << endl; }
    void showInfo(){
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
        cout << "취미 : " << hobby << endl;
    }
};
class Student : public Human {
private:
    char school[30];
public:
    Student(int _age, char *_name, char *_hobby, char *_school) : Human(_age, _name, _hobby){
        strcpy(school, _school);
    }
    void schoolInfo(){
        showInfo();
        cout << "학교 : " << school << endl;
    }
};

class Friend_B;
class Friend_A{
private:
    int adata;
public:
    Friend_A(int _data){
        adata = _data;
    }
    void show(Friend_B b);
    friend class Friend_B;
};

class Friend_B{
private:
    int bdata;
public:
    Friend_B(int _data){
        bdata = _data;
    }
    void show(Friend_A a){
        cout << "a.data : " << a.adata << endl;
    }
    friend class Friend_A;
};

void Friend_A::show(Friend_B b){
    cout << "b.data : " << b.bdata << endl;
}

class deep{
private:
    char *str;
public:
    deep(const char *_str){
        str = new char[strlen(_str)+1];
        strcpy(str, _str);
    }
    deep(const deep& dp){
        str = new char[strlen(dp.str)+1];
        strcpy(str, dp.str);
    }
    ~deep(){
        delete []str;
        cout << "~deep()" << endl;
    }
    void show(){
        cout << "str : " << str << endl;
    }
};

class shallow{
private:
    char *str;
public:
    shallow(const char *_str){
        str = new char[strlen(_str)+1];
        strcpy(str, _str);
    }
    ~shallow(){
        delete []str;
        cout << "~shallow()" << endl;
    }
    void show(){
        cout << "str: " << str << endl;        
    }
};

class dog{
public:
    dog(){
        cout << "dog()" << endl;
    }
    ~dog(){
        cout << "~dog()" << endl;
    }
};

class copied{
private:
    int num1;
    int num2;
public:
    copied(int a, int b){
        num1 = a;
        num2 = b;
    }
    void show(){
        cout << "num1 : " << num1 << " num2 : " << num2 << endl;
    }
};

class human{
private:
    char *name;
    int age;
public:
    human();
    human(char *_name);
    human(char *_name, int age);
    void ShowInfo();
};
human::human(char *_name, int _age){
    name = _name;
    age = _age;
}
human::human(char *_name){
    cout << "human(char name) overloading" << endl;
}
human::human(){
    cout << "human() overloading" << endl;
}
void human::ShowInfo(){
    cout << "이름 : " << name << " 나이 : " << age << endl;
}

class child{
private:
    char *name;
    int age;
    char *hobby;
public:
    void ShowInfo();
    void SetInfo(char *_name, int _age, char *_hobby);
    void Study();
    void Sleep();
};
void child::ShowInfo(){
    cout << "이름 : " << name << " 나이 : " << age << " 취미 : " << hobby << endl;
}
void child::SetInfo(char *_name, int _age, char *_hobby){
    name = _name;
    age = _age;
    hobby = _hobby;
}
void child::Study(){
    cout << "공부!" << endl;
}
void child::Sleep(){
    cout << "잠!" << endl;
}

struct user{
private:
    int id;
    char *name;
    float exp;
public:
    void show();
    void setInfo(int _id, char * _name, float _exp);
};

void user::show(){
    cout << "번호 : " << id << endl;
    cout << "이름 : " << name << endl;
    cout << "경험 : " << exp << endl;
}

void user::setInfo(int _id, char * _name, float _exp){
    id = _id;
    name = _name;
    exp = _exp;
}

struct player{
    int id;
    char name[24];
    float exp;
    
    void show(){
        cout << "번호 : " <<id << endl;
        cout << "이름 : " <<name << endl;
        cout << "경험 : " <<exp << endl;
    }
    void show_Example2();
};

void player::show_Example2(){
    cout << "번호 : " <<id << endl;
    cout << "이름 : " <<name << endl;
    cout << "경험 : " <<exp << endl;
}

void func(int a){ cout << "int a : " << a << endl; }
void func(int a, int b){ cout << "int a : " << a << " int b : " << b << endl; }

void NewDeleteExample(){
    int len, total=0; int * score; int i;    
    cout << "학생수 입력 : ";
    cin >> len;
    
    score = new int[len];
    
    for(i=0; i<len; i++){
        cout << i+1 << "번 학생의 점수: ";
        cin >> score[i];
        total += score[i];
    }
    cout << "모든 학생의 평균: " << total/len << endl;
    delete []score;
}

void boolNum(){
    cout << true << endl;
    cout << false << endl;
}

void boolLen(){
    cout << "sizeof true: " << sizeof true << endl;
    cout << "sizeof false: " << sizeof false << endl;
}

void boolExample(){
    int a, b;
    bool isMax;
    
    cin >> a >> b;
    
    if(a>b) isMax = true;
    else isMax = false;
    
    cout << "isMax : " << isMax << endl;
}

void inlineExample(){
    cout << PI << endl;
    cout << CU(7.4) << endl;
}

void referenceExample(){
    int aaa=50;
    int &bbb=aaa;
    
    cout << "aaa : " << aaa << endl;
    cout << "bbb : " << bbb << endl;
    
    cout << "aaa path : " << &aaa << endl;
    cout << "bbb path : " << &bbb << endl;
}

void swap(int &ref_a, int &ref_b){
    int temp = ref_a;
    
    ref_a = ref_b;
    ref_b = temp;
}
void callByReferenceExample(){
    
    int a = 50, b = 40;
    cout << "swap 하기전 a : " << a << " b : " << b << endl;
    
    swap(a, b);
    cout << "swap 한 후 a : " << a << " b : " << b << endl;
}

void objectArrayExample(){
    Item item[2];
    
    int id, price;
    char name[10];
    
    for(int i=0; i<2; i++){
        cout << "id : ";
        cin >> id;
        cout << "name : ";
        cin >> name;
        cout << "price : ";
        cin >> price;
        
        item[i].setInfo(id, name, price);
    }
    for(int i=0; i<2; i++){
        item[i].getInfo();
    }
}

void objectArrayExample_memberInitializer(){
    ItemEX itemEx[2] = {ItemEX(1, "apple", 500),ItemEX(1, "box", 1000)};
    for(int i=0; i<2; i++){
        itemEx[i].getInfo();
    }
}

void objectPointerArray(){
    ItemEX * itemEx[2];
    
    int id, price;
    char name[10];

    for(int i=0; i<2; i++){
        cin >> id >> name >> price;
        itemEx[i] = new ItemEX(id, name, price);
    }
    for(int i=0; i<2; i++){
        itemEx[i]->getInfo();
	}
    delete itemEx[0];
    delete itemEx[1];
}

void virtualFunctionExample(){
    virtual_Parent vP, *pP;
    virtual_Child vC;
    pP = &vP;
    pP ->func();
    pP = &vC;
    pP -> func();
}

void pureVirtualFunctionExample(){
    pure_virtual_Parent * P;
    P = new pure_virtual_Child;
    P -> func();
}

void multipleInheritanceExample(){
    multipleInheritance_Child child;
    child.func();
}

void operatorOverloadingExample(){
    NumBox nb_a(10, 20);
    NumBox nb_b(5, 2);
    NumBox result = nb_a + nb_b;
    NumBox result2 = nb_a.operator+(nb_b);
    
    nb_a.show();
    nb_b.show();
    result.show();
    result2.show();
}

void functionTemplateExample(){
    int num_a=10, num_b=40;
    cout << "swap 전 : num_a : " << num_a << " num_b : " << num_b << endl;
    template_Swap(num_a, num_b);
    cout << "swap 후 : num_a : " << num_a << " num_b : " << num_b << endl;
    
    double num_c=15.6, num_d = 14.44;
    cout << "swap 전 : num_c : " << num_c << " num_d : " << num_d << endl;
    template_Swap(num_c, num_d);
    cout << "swap 후 : num_c : " << num_c << " num_d : " << num_d << endl;
}

void classTemplateExample(){
    Data<int> data_a(50);
    data_a.show();
    
    Data<char> data_b('A');
    data_b.show();
    
    Data<double> data_c(14.345);
    data_c.show();
}

void exceptionHandlingExample(){
    int a, b;
    
    cout << "두개의 정수 입력 : ";
    cin >> a >> b;
    if(b == 0)
        cout << "나누는 수가 0이 될 수 없음 " << endl;
    else
        cout << a << "를 " << b << "로 나눈 몫 : " << a/b << endl;
}

void trycatchThrowExample(){
    int a, b;
    
    cout << "두개의 정수 입력: ";
    cin >> a >> b;
    
    try{
        if(b == 0) throw b;
        cout << a << "를 " << b << "로 나눈 몫 : " << a/b << endl;
    }catch (int exception){
        cout << "예외 발생 : 나누는 수가 0이 될 수 없음" << endl;
    }
}

void exceptionFunc(int a, int b){
    if(b == 0) throw b;
    cout << a << "를 " << b << "로 나눈 몫 : " << a/b << endl;
}

void functionExceptionHandlingExample(){
    int a, b;
    
    cout << "[function exception] 두개의 정수 입력: ";
    cin >> a >> b;
    
    try{
        exceptionFunc(a, b);
    } catch(int exception){
        cout << "예외 발생 : 나누는 수가 0이 될 수 없음" << endl;
    }
}

void stackunwindingFunc_a(){ throw 0; }
void stackunwindingFunc_b(){ stackunwindingFunc_a(); }
void stackunwindingFunc_c(){ stackunwindingFunc_b(); }
void stackunwindingFunc_d(){ stackunwindingFunc_c(); }

void stackUnwindingExample(){
    try{
        stackunwindingFunc_d();
    } catch(int exception){
        cout << "예외 발생 : " << exception << endl;
    }
}

int sum(int a, int b){ return a+b;}
void functionPointerExample(){
    int (*pf)(int, int) = sum;
    
    cout << "pf : " << pf(7, 3) << endl;
    cout << "sum : " << sum(7, 3) << endl;
    
    cout << "pf 주소 : " << pf << endl;
    cout << "sum 주소 : " << sum << endl;
}

void memberFunctionPointerExample(){
    Rectangle rc(10, 5);
    /* 함수 원형에 따라 아래와 같이 함수 포인터를 선언 */
    int (Rectangle::*pf)(void) = &Rectangle::area;
    /* pf가 Rectangle클래스에서 area 멤버 함수의 시작 주소를 가리키도록 함 */
    
    cout << "rc.area() : " << rc.area() << endl;
    cout << "(rc.*pf)() : " << (rc.*pf)() << endl;
    /* rc.area()와 (rc.*pf)()의 반환값을 출력함 두 결과값은 동일하다는걸 알 수 있음 */
    
    /*  (rc.*pf)()처럼 객체를 통해 멤버 함수를 호출할 때에는 .*연산자가 사용됨
        만약 연산자 우선순위 때문에 괄호를 제거하여 rc.*pf()와 같이 호출하면 오류가 발생한다고 함. 반드시 괄호 포함
    */
    
    /*  만약 Lion클래스의 cry()함수 원형이 아래와 같다고 가정
        void Lion::cry()
        이는 반환형이 void고 매개변수의 타입도 void임 그리고 cry()함수는 Lion 클래스의 멤버 함수임
        
        아래와 같이 함수 포인터를 선언할 수 있다고 함.
        void (Lion::*pf)() = &Lion::cry;
    */
}

int main() {
  
    Bike bike; /* 바이크 생성*/
    bike.initPlayer("bikeman", 100); /* 이닛 이름이랑 기름 정의해줌*/
    bike.bikeAccel();
    bike.bikeAccel();
    bike.bikeAccel(); /* 부왕 부왕 부왕 세번함 */
    bike.showBikeState(); /* 계기판을 쓰윽 흝어봄 엑셀을 당김으로 엔진이 돌아서 기름이 일정량 빠져나감 */
    bike.bikeBreak(); /* 너무 빨라서 멈춤 끼이 익*/
    bike.showBikeState(); /* 속도보고 안도함 다리가 후덜덜*/
    
    Car u4biCar;
    u4biCar.initMembers("u4bi", 100);
    u4biCar.Accel();
    u4biCar.Accel();
    u4biCar.Accel();
    u4biCar.showCarState();
    u4biCar.Break();
    u4biCar.showCarState();
  
    memberFunctionPointerExample();

    functionPointerExample();
    
    stackUnwindingExample();
    
    functionExceptionHandlingExample();
    
    trycatchThrowExample();
    
    exceptionHandlingExample();
    
    classTemplateExample();
    
    functionTemplateExample();
    
    operatorOverloadingExample();
    
    multipleInheritanceExample();
    
    pureVirtualFunctionExample();
    
    virtualFunctionExample();
    
    overriding_B ob;
    ob.over();
    
    ThisPointExample tp(10, 20);
    tp.getInfo();
    
    objectPointerArray();
    
    objectArrayExample();
    objectArrayExample_memberInitializer();
    
    memInit mi(50, 70);
    mi.show();
    
    Student stu(12, "u4bi", "coding", "c++ school");
    stu.schoolInfo();
    stu.getup();
    stu.eat();
    stu.study();
    stu.sleep();
    
    Friend_A friend_a(10);
    Friend_B friend_b(20);
    friend_a.show(friend_b);
    friend_b.show(friend_a);

    callByReferenceExample();
    referenceExample();
    inlineExample();
    
    boolNum();
    boolLen();
    boolExample();

    deep dp1("deep copy");
    deep dp2 = dp1;
    dp1.show();
    dp2.show();
    
    /* deep copy test comment line
    shallow sw1("shallow copy");
    shallow sw2 = sw1;
    sw1.show();
    sw2.show();
    */
    
    dog d;

    copied cp1(30, 31);
    copied cp2 = cp1;
    cp2.show();
    
    human h("u4bi", 12);
    h.ShowInfo();
    
    child c;
    c.SetInfo("u4bi", 11, "c++");
    c.ShowInfo();
    c.Study();
    c.Sleep();
    
    user u;
    u.setInfo(123, "u4bi", 55.6);
    u.show();
    
    player p = {1, "u4bi", 67.5};
    cout << "번호 : " <<p.id << endl;
    cout << "이름 : " <<p.name << endl;
    cout << "경험 : " <<p.exp << endl;
    
    p.show();
    p.show_Example2();
    
    int * ptr1 = new int;
    int * ptr2 = new int[10];
    delete ptr1;
    delete []ptr2;
    
    func(4);
    func(5, 6);
    
    good();
    
    win();
    github::lose();
    
    A::Add();
    B::Add();

    NewDeleteExample();

    char name[10];
    int age;
    std::cin>>name>>age;
    std::cout << "내 닉네임은 " << name << "이며 " << age << "살입니다." <<std::endl;
    std::cout << "u4bi c++ workspace" <<std::endl;
    return 0;
}