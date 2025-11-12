#include<bits/stdc++.h>
using namespace std;
#define int long long
int nx[1000005];
int mod=998244353;
int n,m;
int cc(int s){
	int cd=1;
	int bd=1;
	for(int i=1;i<=s;i++){
		bd*=i;
		bd%=mod;
	}
	for(int i=n;i>=n-s+1;i--){
		cd*=i;
		cd%=mod;
	}
	return (cd/bd)%mod;
}
void solve(){
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>nx[i];
	}
	int dd=0;
	for(int i=m;i<=n;i++){
		dd+=cc(i);
		dd%=mod;
	}
	cout<<dd;
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
