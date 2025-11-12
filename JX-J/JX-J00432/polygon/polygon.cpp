#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,ans=0,a,b,c;
cin>>n;
if(n<3){
	cout<<ans;
	return 0;
}
cin>>a>>b>>c;
if(a+b>c && a+c>b && b+c>a){
	ans++;
	cout<<ans;
	return 0;
}
cout<<ans;
	return 0;
}
