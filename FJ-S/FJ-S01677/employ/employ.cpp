#include<iostream>
#include<string>
#include<cstdio>
#define int long long
using namespace std;
int n,m;
int a[501];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	bool f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'==0) f=1;
	}
	if(f && m==n)cout<<0;
	else if(!f){
		for(int i=1;i<=n;i++) ans*=i;
		cout<<ans;
	}
	else cout<<1;
}
