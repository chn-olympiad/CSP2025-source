#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
int n,m,k;
struct node{
	int v,w;
};
vector<node> ma[N];
int c[15],a[15][N];
priority_queue<node> pq;
int ans;
bool vis[N];

bool operator<(node a,node b)
{
	return a.w>b.w;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ma[u].push_back({v,w});
		ma[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			for(int l=1;l<=n;l++)
				if(l!=j){
					ma[j].push_back({l,c[i]+a[i][j]+a[i][l]});
					ma[l].push_back({j,c[i]+a[i][j]+a[i][l]});
				}
	vis[1]=1;
	for(int i=0;i<ma[1].size();i++)
		pq.push(ma[1][i]);
	int z=n-1;
	while(!pq.empty()&&z){
		int v=pq.top().v,w=pq.top().w;
		pq.pop();
		if(vis[v]) continue;
		z--;
		vis[v]=1;
		ans+=w;
		for(int i=0;i<ma[v].size();i++)
			pq.push({ma[v][i]});
	}
	cout<<ans<<'\n';
	return 0;
}
