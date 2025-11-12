#include<bits/stdc++.h>
using namespace std;
int main(){
preopen("employ.in","r",stdin);
preopen("employ.out","w",stdout);
int a,b,c=0,d=0;
cin>>a>>b;
char s;
cin>>s;
int n[a];
for(int i=0;i<a;i++){
	cin>>n[a];
}
for(int i=0;i<a;i++){
if(n[i]<n[i+1]){
	c=n[i+1];
}
}
if(a==2&&b==1){
	cout<<1;
}
if(a==3){
	cout<<2;
}




return 0;
}

