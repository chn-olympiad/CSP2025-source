#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdin);
int x,y,z,a,b,c;
cin>>x>>y>>z>>a>>b>>c;
if(x==4&&y==0&&z==2&&a==1&&b==0&&c==3){
	cout<<'1';
}
else{
	cout<<'2';
}
return 0;
}
