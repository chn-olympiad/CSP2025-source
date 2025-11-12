#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll n,m,k;
ll a[10005][10005]={0},t[10005]={0};
ll dp[10005][10005]={0};
ll s[10005][10005]={0};
bool l[10005]={0};
vector<ll> p[10005];
ll ans=0x3f3f3f3f;
//void dfs(ll k,ll u){
//	for(int i=0;i<p[u].size();i++){
//		if(!l[p[u][i]]){
//			l[p[u][i]]=1;
//			dp[u][p[u][i]]=dp[p[u][i]][u]=min(dp[u][p[u][i]],s[u][p[u][i]]);
//			dfs(k+1,p[u][i]);
//			l[p[u][i]]=0;
//		}
//		
//	}
//	return ;
//}
void solve(ll k){
	for(int i=1;i<=n;i++){
		dp[k][i]=min(dp[k][i],a[k][i]+t[k]);
	}
}
void dfs1(ll k,ll u,ll x){
	if(k>=n){
		ans=min(ans,x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(s[u][i]!=0 && !l[i]){
			l[i]=1;
			dfs1(k+1,i,x+s[u][i]);
			l[i]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,t;
		cin>>u>>v>>t;
		p[u].push_back(v);
		p[v].push_back(u);
		s[u][v]=s[v][u]=t;
	}

	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			if(j==1)cin>>t[i];
			else cin>>a[i][j-1];
			if(i==j-1){
				t[i]+=a[i][j-1];
				a[i][j-1]=0;
			}
		}
	}
	if(k==0){
		l[1]=1;
		dfs1(1,1,0);
		cout<<ans;
		return 0;
	}
//	for(int i=1;i<=n;i++){
//		l[i]=1;
//		dfs(1,i);
//		l[i]=0;
//	}
	for(int i=1;i<=k;i++){
		solve(i);
	}
	for(int i=1;i<=n;i++){
		dfs1(1,i,0);
	}
	cout<<ans<<endl;
}
