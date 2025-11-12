#include<bits/stdc++.h>
using namespace std;
int a,b,c[10010],d,e,f=1,g,h,ab;
int main(){
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
cin>>a>>b;
int ab=a*b;
for(int i=1;i<=ab;i++){
    cin>>c[i];
    d=c[1];
}
for(int i=2;i<=ab;i++){
    if(c[i-1]<c[i]){
        e=c[i-1];
        c[i-1]=c[i];
        c[i]=e;
    }
}
for(int i=1;i<=ab;i++){
    if(c[i]==d){
         break;
    }
       f++;
}
g=f%(a+b);
h=f/(a+b)+1;
if(f%2==0){
    g=a-(g+1);
}
cout<<h<<" "<<g;
return 0;
}
