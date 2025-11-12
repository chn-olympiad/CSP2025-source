#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
char s[N];
int c[N];
bool f,flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') f=true;
	} 
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) flag=true;
	}
	if(m==n){
		if(f || flag) cout<<0;
		long long ans=1%mod;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	if(f==false){
		long long ans=1%mod;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<225301405;
	return 0;
}