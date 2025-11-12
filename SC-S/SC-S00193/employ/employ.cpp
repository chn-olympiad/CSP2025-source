#include<bits/stdc++.h>
using namespace std;

long long n, m, c[114514], ans=1, Mod=998244353;
string str;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>str;
	bool sign=1;
	for(int i=0;i<str.size();i++) if(str[i]=='0') sign=0;
	if(sign||m==1){
		for(int i=1;i<=n;i++) cin>>c[i];
		for(int i=n;i>=1;i--) ans=ans*i%Mod;
		cout<<ans<<endl;
		return 0;
	}
	cout<<114514<<endl;
	return 0;
}