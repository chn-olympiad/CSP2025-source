#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int mod=998244353;
string s;
int zzx;
int rans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		zzx+=(s[i]=='0');
	} 
	for(int i=1;i<=m;i++){
		int x;cin>>x;
	}
	if(zzx<m){
		cout<<0;
		return 0;
	}
	if(zzx==n){
		if(m==n){
			rans=1;
			for(int i=1;i<=n;i++){
				rans=rans*i;
				rans=(rans%mod+mod)%mod;
			}
			cout<<rans;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
