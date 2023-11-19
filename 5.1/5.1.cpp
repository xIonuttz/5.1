#include <iostream>

class A {
public:
    int aa;
protected:
    int ab;
private:
    int ac;

public:
    void testA() {
        aa = 1;    // public
        ab = 2;    // protected
        ac = 3;    // private
    }
};

class B : public A {
public:
    int ba;
protected:
    int bb;
private:
    int bc;

public:
    void testB() {
        // Access to members of class B
        ba = 4;    // public in B
        bb = 5;    // protected in B
        bc = 6;    // private in B

        // Access to members of class A
        aa = 7;    // public in A (inherited)
        ab = 8;    // protected in A (inherited)
     
        testA();   // Access public method in A
    }
};

class C : private B {
public:
    int ca;
protected:
    int cb;
private:
    int cc;

public:
    void testC() {
        // Access to members of class C
        ca = 10;   
        cb = 11;   
        cc = 12;   

        // Access to members of class B (inherited privately)
        ba = 13;  
        bb = 14;   
       

        // Access to members of class A (inherited through B privately)
        aa = 16;   
        ab = 17;   
        

        // Access public methods in B and A
        testB();  
       
    }
};

int main() {
    
    A a;
    B b;
    C c;

    // Call test methods
    a.testA();   
    b.testB();  
    c.testC();   

    return 0;
}
