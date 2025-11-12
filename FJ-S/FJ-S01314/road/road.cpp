#include<bits/stdc++.h>
using namespace std;
const int N=10020;
const int M=1000005;
int n,m,k,dis[N],vis[N],c[15],a[15][N],z;
struct point{
	int v,w,d;
	bool operator < (const point a) const
	{
		return w<a.w;
	}
};
vector<point> e[N];
priority_queue<point,vector<point> >q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back((point){v,w});
		e[v].push_back((point){u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	q.push((point){1,0,0});
	while(!q.empty()){
		point w=q.top();
		q.pop();
		int u=w.v;
		if(vis[u])continue;
		vis[u]=1;
		dis[u]=w.w;
		z+=w.d;
		int l=e[u].size();
		for(int i=0;i<l;i++){
			int v=e[u][i].v;
			if(!vis[v]){
				q.push((point){v,dis[u]-e[u][i].w,e[u][i].w});
			}
		}
	}
	cout<<z;
	fclose(stdin);fclose(stdout);
	return 0;
}