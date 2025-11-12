#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	bool flag;
	for(int i=0;i<s.size();i++){
		if(s[i]==0){flag=0; break;}
	}
	if(flag==1){
		long long x=1,y=1,z=1;
		for(int i=1;i<=n;i++) x*=i;
		for(int i=1;i<=m;i++) y*=i;
		for(int i=1;i<=n-m;i++) z*=i;
		cout<<(x/(((y%mod)*(z%mod))%mod))%mod;
	}
	if(m==1){
		int cnt=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1') cnt++;
		}
		cout<<cnt%mod;
	}
	if(m==n){
		if(flag==1) cout<<1;
		else cout<<0;
	}
	return 0;
}
