#include<iostream>
using namespace std;
int main(){
int h=0,l=0,x,y,n;
x(seat.in);
y(seat.in);
int s[x*y]+10;
s[x*y+10](seat.in);
n=x*y+10;
int h=0,j=0;
j=s[1];

for(int i=1; i<=n; i++){
    if(s[i]<s[i+1]){
        h=s[i+1];
        s[i+1]=s[i];
        s[i]=h;
    }
}

for(int m=1; m<=n; n++){
    if(s[m]==j)
        h=m;
}

int a=0,b=0;
if(h/x>0){
b=h/x+1;
a=(h-x)%x;
}
else{
a=h%x;
b=1;
}

a(seat.out);
b(seat.out);
return 0;
}
