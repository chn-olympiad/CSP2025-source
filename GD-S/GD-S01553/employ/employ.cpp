#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,A=1,B,s[505],c[505],ans,v[505],fact[505];
void dfs(int dep,int cnt) {
	if(cnt==m) {
		ans=(ans+fact[n-dep])%mod;
		return;
	}
	if(dep==n) return;
	for(int i=1;i<=n;i++) {
		if(v[i]) continue;
		v[i]=1;
		if(c[i]<=dep-cnt||!s[dep+1]) dfs(dep+1,cnt);
		else dfs(dep+1,cnt+1);
		v[i]=0;
	}
}
void work() {
	cin>>n>>m;
	fact[0]=1;
	for(int i=1;i<=n;i++) {
		char j;
		cin>>j;
		s[i]=j=='1';
		if(!s[i]) A=0;
		fact[i]=fact[i-1]*i%mod;
	}
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	dfs(0,0);
//	if(A) {
//		int ans=1;
//		for(int i=n;i-1;i--) {
//			ans=ans*i%mod;
//		}
//		cout<<ans;
//		return;
//	}
//	if(m==1) {
//		int t=1,ans=0;
//		for(int i=1;i<=n;i++) {
//			int cnt=1;
//			for(int j=i;j<n;j++,cnt++) if(c[j]!=c[j+1]) break;
//			
//		}
//	}
	cout<<ans;
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int t=1;
//	cin>>t;
	while(t--) {
		work();
	}
	return 0;
}
