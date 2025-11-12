#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000001;
int n,m,k,ans,sum;
struct node{
	int v,w;
};
int cy[15];
bool use[10025];
int dis[10025];bool vis[10025];
vector<node> g[10025]; 
void Prim(int arr){
	for(int i=1;i<=n+k;i++)
		dis[i]=inf,vis[i]=0;
	dis[1]=0;
	for(int i=1;i<=n+arr;i++){
		int mp=0,minn=inf;
		for(int j=1;j<=n+k;j++)
			if(!vis[j] && use[i] && dis[j]<minn)
				mp=j,minn=dis[j];
		ans+=minn;vis[mp]=1;
		for(int j=0;j<g[mp].size();j++){
			node vv=g[mp][j];
			if(!vis[vv.v] && use[vv.v] && dis[vv.v]>vv.w)
				dis[vv.v]=vv.w;
		}
	}
	return;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		use[i]=1;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=n+1;i<=n+k;i++){
		int fee;
		cin>>fee;
		cy[i]=fee;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			g[i].push_back({j,w});
			g[j].push_back({i,w});
		}
	}
	sum=inf;
	for(int i=0;i<(1<<k);i++){
		for(int i=n+1;i<=n+k;i++)
			use[i]=0;
		int arr=i,ji=1+n;
		while(arr){
			if(arr&1)
				use[ji]=1;
			arr>>=1;
			ji++;
		}
		ans=0;int arrn=0;
		for(int i=n+1;i<=n+k;i++){
			if(use[i])
				ans+=cy[i],arrn++;
		}
		Prim(arrn);
		sum=min(sum,ans);
	}
	cout<<sum<<'\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
