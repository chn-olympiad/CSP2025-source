#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
struct node{
	ll v,w; 
};
ll a[20][10005];
ll dis[10005];
vector<node> e[10005];
struct aa{
	ll id,w;
};
int c[15];
int vis[10005];
bool operator<(const aa& a,const aa& b){
	return a.w>b.w;
}
int cnt;
bool flaga=1;
ll res;
void prim(){
	priority_queue<aa> que;
	que.push({1,0});
	dis[1]=0;
	res=0;
	while(!que.empty()){
		aa u=que.top();
		if(vis[u.id]){
			que.pop();
			continue;	
		}
		vis[u.id]=1;
		res+=u.w;
		++cnt; 
		if(cnt==n) break;
		que.pop();
		for(int i=0;i<e[u.id].size();++i){
			int v=e[u.id][i].v;
			if(dis[v]>e[u.id][i].w){
				dis[v]=e[u.id][i].w;
				if(!vis[v])
				que.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,0x7f,sizeof(dis));
	for(int i=1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	} 
	for(int i=1;i<=k;++i){
		cin>>c[i];
		if(c[i]!=0) flaga=0;
		for(int j=1;j<=n;++j){
			scanf("%lld",&a[i][j]);
			
		}
	}
	if(k==0){
		prim();
		printf("%lld\n",res);
	}
	else if(flaga){
		for(int sk=1;sk<=k;++sk){
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					e[j].push_back({i,a[sk][i]+a[sk][j]});
					e[i].push_back({j,a[sk][i]+a[sk][j]});
				}
			}
		}
		prim();
		printf("%lld\n",res);
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4


*/

