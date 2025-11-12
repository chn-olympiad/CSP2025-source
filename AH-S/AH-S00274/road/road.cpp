#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,k;
vector<pair<LL,int> >mp[10005];
LL c[15];
LL a[15][10005];
vector<pair<LL,pair<int,int> > >bian;
bool vis[10015];
LL least=0x3f3f3f3f3f3f3f3f;
bool p[15];
void dfs(int K){
	if(K==k+1){
		bian.clear();
		memset(vis,0,sizeof(vis));
		LL ans=0;
		for(int u=1;u<=n;u++){
			for(auto tmp:mp[u]){
				int v=tmp.second;
				LL w=tmp.first;
				if(v>=u) bian.push_back(make_pair(w,make_pair(u,v)));
			}
		}
		for(int i=1;i<=k;i++){
			if(p[i]){
				ans+=c[i];
				for(int u=1;u<=n;u++){
					bian.push_back(make_pair(a[i][u],make_pair(u,n+i)));
				}
			}
		}
		sort(bian.begin(),bian.end());
		for(auto tmp:bian){
			LL w=tmp.first;
			int u=tmp.second.first;
			int v=tmp.second.second;
			if(vis[u]&&vis[v]) continue;
			//printf("%d %d %lld\n",u,v,w);
			vis[u]=vis[v]=1;
			ans+=w;
		}
		least=min(least,ans);
		//printf("%lld\n",ans);
		return;
	}
	p[K]=0;
	dfs(K+1);
	p[K]=1;
	dfs(K+1);
	p[K]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;
		LL w;
		scanf("%d%d%lld",&u,&v,&w);
		mp[u].push_back(make_pair(w,v));
		mp[v].push_back(make_pair(w,u));
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	//printf("%d %d %d\n",n,m,k);
	dfs(1);
	printf("%lld",least);
	return 0;
}
