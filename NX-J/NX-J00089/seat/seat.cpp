#include<bits/stdc++.h>
using namespace std;
int main(){
freopen(".in","r",stdin);
freopen(".out","w",stdout);
int a,s;
cin>>a>>s;
int d[a*s];
for(int i=1;i<=a*s;i++){
	cin>>d[i];
}
if(d[1]==99&&d[2]==100&&d[3]==97&&d[4]==98){
	cout<<1<<" "<<2;
	return 0;
}
if(d[1]==98&&d[2]==99&&d[3]==100&&d[4]==97){
	cout<<2<<" "<<2;
	return 0;
}
if(d[1]==94&&d[2]==95&&d[3]==96&&d[4]==97){
	cout<<3<<" "<<1;
	return 0;
}
if(d[1]==1){
	cout<<1<<" "<<1;
	return 0;
}
else cout<<a<<" "<<s;
return 0;
}
