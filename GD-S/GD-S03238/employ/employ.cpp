#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=5e2+5,mod=998244353;
int n,m,c[N],sum,t;
bool vis[N];
LL ans;
string s;
void dfs(int o,int k,int sum){
	if(o>n){
		if(k>=m){
			ans++;
			if(ans>=mod) ans-=mod;
		}
		return ;
	}
	for(rint i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
		if(sum<c[i]&&s[o]=='1') dfs(o+1,k+1,sum);
		else dfs(o+1,k,sum+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(rint i=1;i<=n;++i){
		cin>>c[i];
		if(s[i]=='0') t++;
	}
	if(n-t<m) return cout<<0,0;
	if(m==n){
		ans=1;
		for(LL i=1;i<=n;++i){
			ans=ans*i%mod;
			if(c[i]==0) ans=0;
		}
		return cout<<ans,0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

