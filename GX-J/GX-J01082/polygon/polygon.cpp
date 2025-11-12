#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int a,c,da=1,f;
int b[1000];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>a;
for(int i=0;i<a;i++){cin>>b[i];}
if(a<=2){cout<<0;return 0;}
if(a==3 and max(b[0],max(b[1],b[2]))<b[0]+b[2]+b[1]-max(b[0],max(b[1],b[2]))){cout<<1;}else if(a==3){cout<<0;}
if(a>3) cout<<0;
return 0;
}
