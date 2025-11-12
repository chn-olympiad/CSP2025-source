#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
struct node{
	long long v,w;
	bool operator<(const node &t)const&
	{return this->w<t.w;}
};
long long n,m,k,u,v,w,c[15],a[15][10005],dis[10005],ans;
vector<node>e[10005];
bool vis[10005];
void prim(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().v;
		if(vis[u]){
			q.pop();
			continue;
		}
		q.pop();
		vis[u]=1;
		for(auto it:e[u]){
			if(dis[it.v]>dis[u]+it.w){
				dis[it.v]=dis[u]+it.w;
				q.push({it.v,dis[it.v]});
				ans+=it.w;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	prim(1);
	cout<<ans;
	return 0;
}
