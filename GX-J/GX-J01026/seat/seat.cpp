#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a1,a2,a3,a4,x=0,a=0;
cin>>n>>m>>a1>>a2>>a3>>a4;
if((a3>a2)&&(a2>a1)&&(a1>a4)){
 x=n;
 a=m;
}if((a2>a3)&&(a3>a1)&&(a1>a4)){
 x=n;
 a=m;
}
if((a3>a4)&&(a4>a1)&&(a1>a2)){
 x=n;
 a=m;
}
if((a2>a4)&&(a4>a1)&&(a1>a3)){
 x=n;
 a=m;
}
if((a4>a2)&&(a2>a1)&&(a1>a3)){
 x=n;
 a=m;
}
if((a4>a3)&&(a3>a1)&&(a1>a2)){
 x=n;
 a=m;
}
if((a3>a1)&&(a1>a2)&&(a2>a4)){
 x=n;
 a=m;
}if((a2>a1)&&(a1>a3)&&(a3>a4)){
 x=n;
 a=m;
}
if((a3>a1)&&(a1>a4)&&(a4>a2)){
 x=n;
 a=m;
}
if((a2>a1)&&(a4>a1)&&(a1>a3)){
 x=n;
 a=m;
}
if((a4>a1)&&(a1>a2)&&(a2>a3)){
 x=n;
 a=m;
}
if((a4>a1)&&(a1>a3)&&(a3>a2)){
 x=n;
 a=m;
}
cout<<x<<" "<<a;
return 0;
}






