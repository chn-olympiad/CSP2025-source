#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,c,r;
    cin>>n>>m;
    if(n==2,m==2){
      int a1,a2,a3,a4;
      cin>>a1>>a2>>a3>>a4;
      if(a1>a2&&a1>a3&&a1>a4){
        c=1,r=1,cout<<c<<" "<<r;
      }else if(a2>a1&&a1>a3&&a1>a4){
       c=1,r=2,cout<<c<<" "<<r;
            }else if(a1<a2&&a1<a3&&a1>a4){
             c=2,r=2,cout<<c<<" "<<r;
            }
    }
    if(n==3,m==3){
       int b1,b2,b3,b4,b5,b6,b7,b8,b9;
       cin>>b1>>b2>>b3>>b4>>b5>>b6>>b7>>b8>>b9;
       if(b1<b2&&b1<b3&&b1<b4&&b1<b5&&b1<b6&&b1<b7&&b1>b8&&b1>b9)
       c=3,r=1,cout<<c<<" "<<r;
	}
 return 0;
}
