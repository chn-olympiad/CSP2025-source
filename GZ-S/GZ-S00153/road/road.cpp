//GZ-S00153 贵阳雅礼高级中学（贵阳市第九中学） 张宛钰
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+20;
int n,m,k,ans=0x3f3f3f3f3f;
int cnt[maxn],che;
vector<int>G[maxn],F[maxn];
int dfs(int fa,int to,int xf){
	if(che==to) return xf;
	for(int i=0;i<G[fa].size();i++){
		if(cnt[G[fa][i]]==0){
			cnt[G[fa][i]]=F[fa][i];
			xf+=F[fa][i];
			che++;
		}
		else{
			int p=xf-cnt[G[fa][i]]+F[fa][i];
			xf=min(xf,p);
			if(xf==p) cnt[G[fa][i]]=F[fa][i];
		}
		dfs(G[fa][i],to,xf);
		xf-=cnt[G[fa][i]];
		che--;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,q;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>q;
		G[u].push_back(v);
		G[v].push_back(u);
		F[u].push_back(q);
		F[v].push_back(q);
	}
	if(k==0) ans=dfs(1,n,0);
	for(int i=1;i<=k;i++){
		cin>>q;
		for(int j=1;j<=n;j++){
			cin>>u;
			G[n+1].push_back(i);
			G[i].push_back(n+1);
			F[n+1].push_back(u);
			F[i].push_back(u);
		}
		ans=min(ans,dfs(1,n+1,q));
	}
	cout<<ans;
	return 0;
}
