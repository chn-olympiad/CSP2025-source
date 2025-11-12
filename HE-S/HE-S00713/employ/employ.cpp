#include<bits/stdc++.h>
using namespace std;
const int N=5e2+20;
const int Mod=998244353;
int a[N];
long long f(int x){
	if(x==1)return x;
	return (x*f(x-1))%Mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')break;
		if(i==s.size()-1){
			cout<<f(n);
			return 0;
		}
	}
	int q=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')q+=1;
	}
	if(q<m){cout<<0;return 0;}
	if(m==n){
		for(int i=1;i<s.size();i++){
			if(s[i]=='0'){cout<<"0";return 0;}
		}
	}
	cout<<"0";
	return 0;
}
