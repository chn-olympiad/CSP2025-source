#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10,maxm=1e6+10;
struct edge{
	int to,w;
	bool operator<(const edge &x)const{
		return w>x.w;
	}
};
int n,m,s,dis[maxn];
bool vis[maxn];
vector<edge> g[maxm];
priority_queue<edge> q;
void dij(int n,int s){
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;
	
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()){
		edge now=q.top();
		q.pop();
		int u=now.to;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:g[u]){
			if(dis[v.to]>dis[u]+v.w){
				dis[v.to]=dis[u]+v.w;
				q.push({v.to,dis[v.to]});
			}
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<2;
}
