#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=1e4+10;
struct dk{
	LL v,w;
};
LL n,m,k,vis[N],a[15][N],dp[1030],s[15],m2[15]={1},p,q[N],ans;
vector<dk>t[N];
void dfs(LL s){
	if(vis[s]) return;
	vis[s]=1;
	for(int i=0;i<t[s].size();i++){
		q[++p]=t[s][i].w;
		dfs(t[s][i].v);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=n;i++) m2[i]=m2[i-1]*2;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		LL u,v,w;
		cin>>u>>v>>w;
		t[u].push_back({v,w});
		t[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		LL us;
		cin>>s[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) us=j;
		}
		for(int j=1;j<=n;j++){
			if(j==us) continue;
			t[us].push_back({j,a[i][j]});
			t[j].push_back({us,a[i][j]});
		}
	}
	dfs(1);
	sort(q+1,q+1+p);
	for(int i=2*m-2*n+3;i<=p;i++){
		ans+=q[i];
	}
	cout<<ans/2;
	/*
	for(int i=1;i<m2[k];i++){
		for(int j=1;j<=k;j++){
			if((i>>(j-1))%2){
				dp[i]=dp[i-m2[j-1]]
			}
		}
	}
	*/
	return 0;
}
