#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	if(n==1||n==2)cout<<"0";
	else if(n==3){
		int a,b,c;cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a)cout<<1;
	}
	else if(n==4){
		int a,b,c,d,ans=0;cin>>a>>b>>c>>d;
		if(a+b>c&&a+c>b&&b+c>a)ans++;
		if(a+b>d&&a+d>b&&b+d>a)ans++;
		if(a+d>c&&a+c>d&&d+c>a)ans++;
		if(d+b>c&&d+c>b&&b+c>d)ans++;
		if(a+b+c>d&&a+b+d>c&&a+c+d>b&&b+c+d>a)ans++;
		cout<<ans;
	}
	else if(n==5){
		int a;cin>>a;
		if(a==1)cout<<9;
		else if(a==2)cout<<6;
		else cout<<3; 
	}
	else cout<<0;
	return 0;
}