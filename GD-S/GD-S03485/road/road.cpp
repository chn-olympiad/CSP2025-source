#include<bits/stdc++.h>
#define pii pair<long long,long long>
using namespace std;
const long long M=1e7+25;
long long n,m,k;
vector<pii>g2[M],g[M];
long long c[15][100025];
bool vis[205];
priority_queue<pii,vector<pii>,greater<pii> >pq; 
bool vs[100025];
long long prim(long long s){
	long long res=0,cnt=n;
	pq.push({0,s});
	while(!pq.empty()){
		pii t=pq.top();
		pq.pop();
		long long id=t.second,d=t.first;
		if(vis[id])continue;
		if(cnt==0){
			continue;
		}
		vis[id]=true;
		res+=d;
		if(id<=n)cnt--;
		for(auto i:g[id]){
			long long v=i.first,w=i.second;
			if(vis[v])continue;
			if(v>n&&!vis[v]){	
				pq.push({w+c[v-n][0],v});
			}
			else pq.push({w,v});
		}
	}return res;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}for(long long i=1;i<=k;i++){
		for(long long j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}for(long long i=1;i<=k;i++){
		for(long long j=1;j<=n;j++){
			g[n+i].push_back({j,c[i][j]});
			g[j].push_back({n+i,c[i][j]});
		}
	}
	cout<<prim(1);
	return 0;
}
