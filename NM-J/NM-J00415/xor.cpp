#include<iostream>
using namespace std;
int main(){
int a,b;
char z;
a(xor.in);
b(xor.out);
int n[a],x,z=0,f=0;
z=n[1];
for(int m=2; m<=a; m++)
    f+=n[m];
for(int i=1; i<=a; i++){
    if(n[i]<n[i+1]){
        x=n[i+1];
        n[2]=n[1];
        n[1]=x;
    }
}

if(n[1]>f)
{
x=n[1]-f;
x(xor.out);
}
else{
x=n[1];
x(xor.out)
}
return 0;
}
