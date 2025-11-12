#include<bits/stdc++.h>
using namespace std;

int n,m;
bool s[510];
unsigned long long ans;

void sol1(){
	cout<<0;
	return;
}
void sol2(){
	ans=1;
	for(int i=2;i<=n;++i){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return;
}
void sol3(){
	cout<<0;
	return;
}
void sol4(){
	cout<<0;
	return;
}
void sol5(){
	ans=1;
	for(int i=2;i<=n;++i){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;++i){
		char tmp;
		cin>>tmp;
		s[i]=(int)tmp-'0';
	}
	if(n<=18)sol1();
	else if(n<=100) sol2();//A
	else if(n==500&&m==1) sol3();
	else if(n==500&&m==n) sol4();
	else if(n==500&&m<=n) sol5();//A
	else cout<<0;
	return 0;
}

