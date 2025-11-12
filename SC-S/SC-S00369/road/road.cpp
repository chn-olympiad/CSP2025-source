#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int v,w;
	const bool operator > (edge y) const{
		return this->w > y.w;
	}
};
vector<edge> G[10055];
int w1[15][10005];
int ww1[15];
int n,m,k;
int _nowmin=1e10;
int _nowminid=0;
bool vis[10055];
int tot1;
priority_queue<edge,vector<edge>,greater<edge> > pq;
int chang(int lst,int nxt){
	for(int i=1;lst;i++,lst>>=1){
		if(lst%2==0) continue;
		tot1--;
		G[i+10004].clear();
		for(int j=1;j<=n;j++){
			G[j].pop_back();
		}
	}
	int ys=0;
	for(int i=1;nxt;i++,nxt>>=1){
		if(nxt%2==0) continue;
		ys+=ww1[i];
		tot1++;
		for(int j=1;j<=n;j++){
			if(w1[i][j]<_nowmin) _nowminid=j;
			_nowmin=min(_nowmin,w1[i][j]);
			G[i+10005].push_back({j,w1[i][j]});
			G[j].push_back({i+10005,w1[i][j]});
		}
	}
	return ys;
}
int mn=1e18;
void solve(int id,int tot,int sum){
	if(sum>mn) return ;
//	cout<<1;
//	cout<<tot<<'\n';
	if(tot>=tot1){
		mn=min(mn,sum);
		return ;
	}
	vis[id]=1;
	for(auto x:G[id]){
		if(!vis[x.v])
		pq.push(x);
	}
	while(!pq.empty()&&vis[pq.top().v]){
		pq.pop();
	}
//	cout<<pq.top().v<<':'<<pq.top().w<<'\n';
	solve(pq.top().v,tot+1,sum+pq.top().w);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int _min=1e10;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(w<_min) _nowminid=u;
		_min=min(_min,w);
		G[u].push_back({v,w}); 
		G[v].push_back({u,w});
	}
	_nowmin=_min;
	int dif=_nowminid;
	for(int i=1;i<=k;i++){
		cin>>ww1[i];
		for(int j=1;j<=n;j++){
			cin>>w1[i][j];
		}
	}
	tot1=n;
	int lst=0;
	for(int msk=0;msk<=((1<<(k-1))-1);msk++){
		memset(vis,0,sizeof(vis));
//		cout<<'\n';
		_nowmin=_min;
		_nowminid=dif;
		int ys=chang(lst,msk);
		lst=msk;
		solve(_nowminid,1,ys);
	}
	cout<<mn;
	return 0;
}