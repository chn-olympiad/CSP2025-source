#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=505;
const ll mod = 998244353;
int n,m,a[N];
ll f[N],ans;
char c;
bool p[N];
bool vis[N];
void dfs(int k,int sum,int id){
	if(k==m) return ans=(ans+f[n-id])%mod,void();
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=true;
		dfs(k+(a[i]>sum&&p[id+1]),sum+(a[i]<=sum||!p[id+1]),id+1);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	f[0]=1;
	for(int i=1;i<N;++i) f[i]=(f[i-1]*1ll*i)%mod;
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>c,p[i]=(c=='1');
	for(int i=1;i<=n;++i) cin>>a[i];
	dfs(0,0,0);
	cout<<ans;
}
