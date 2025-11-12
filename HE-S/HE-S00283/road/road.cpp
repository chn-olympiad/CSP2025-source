#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100;
int n,m,k,ans=0,fa[N],w[N],cnt;
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
struct edge{
	int u,v,val;
};
bool cmp(edge a,edge b){
	return a.val<b.val;
}
vector<edge> g;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
		g.push_back({v,u,w});
	}
	for(int i=1;i<=k;i++){
		int t;cin>>t;
		for(int j=1;j<=n;j++){
			cin>>w[j];
		}
		for(int j=1;j<=n;j++){
			for(int p=1;p<=n;p++){
				if(p==j)continue;
				g.push_back({p,j,t+w[j]+w[p]});
			}
		}
	}
	sort(g.begin(),g.end(),cmp);
	for(auto x:g){
		int u=x.u,v=x.v,w=x.val;
		if(find(u)==find(v))continue;
		ans+=w;fa[find(u)]=find(v);
	}
	cout<<ans;
	return 0;
}

