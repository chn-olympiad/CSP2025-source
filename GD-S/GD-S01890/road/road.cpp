#include<bits/stdc++.h>
#define int long long
const int N=1e4+10,M=2e7+10;
using namespace std;
int n,m,sm,k;
struct edge{
	int v,w;
};
vector<edge> e[N],g[N];
//人杰地灵 上善若水 
int c[20],d[20],a[20][N];
int minn=LLONG_MAX;
int dis[N],vit[N];
void solve(int ans){
	for(int i=1;i<=n;i++) e[i]=g[i];
	sm=m;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j) continue;
			int minn=INT_MAX,mini;
			for(int l=1;l<=k;l++){
				if(d[l]==0) continue;
				if(minn>a[l][i]+a[l][j]){
					minn=a[l][i]+a[l][j];
					mini=l;
				}
			}
			e[i].push_back({j,minn});
			e[j].push_back({i,minn});
		}
	}
	memset(vit,0,sizeof(vit));
	memset(dis,127,sizeof(dis));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,1});
	dis[1]=0;
	while(!q.empty()){
		int le=q.top().first,u=q.top().second;
//		cout<<"u="<<u<<endl;
		q.pop();
		if(vit[u]!=0) continue;
		dis[u]=0;
		vit[u]=1;
		ans+=le;
		for(edge vs:e[u]){
			int v=vs.v,w=vs.w;
//			cout<<"v="<<v<<endl;
			if(!vit[v]&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({w,v});
			}
		}
	}
	minn=min(minn,ans);
}
void dfs(int now){
	if(now==k+1){
		int sum=0;
		for(int i=1;i<=k;i++) 
			if(d[i]) sum+=c[i];
		solve(sum);
//		cout<<minn<<endl;
		return ;
	}
	d[now]=1;
	dfs(now+1);
	d[now]=0;
	dfs(now+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.sync_with_stdio(false),cin.tie(0);
	cin>>n>>m>>k;
	
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
//		e[i]={u,v,w,0};
//		g[i]=e[i];
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(flag){ // maybe 24 pts O((m+n*n) log (m+n*n) )
		for(int i=1;i<=k;i++) d[i]=1;
		solve(0);
		cout<<minn;
//		cout<<endl<<clock()<<endl;
		return 0;
	}
	dfs(1);
	cout<<minn;
//	cout<<endl<<clock()<<endl;
	return 0;
}
/*
4 5 0
1 2 3
2 3 7
1 4 5
3 4 3
1 3 6
*/
