#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 10020;
const ll INF = 1234567890123456;

ll n,m,k,x,y,z,c[N],dis[20][N],ans=0,now[N];
vector<ll> g[N],w[N];
bool vis[N],kvis[N];int noww[N];
priority_queue<pair<ll,ll> > pq;
void prim(){
	for(ll i=1;i<=n+k;i++)now[i] = INF;
	now[1] = 0;
	pq.push({0,1});
	while(!pq.empty()){
		x = pq.top().second,z = -pq.top().first;
		pq.pop();
		if(vis[x])continue;
		vis[x] = 1;
		ans+=z;
		if(x<=n){
			if(noww[y]!=0){
				kvis[noww[y]] = 1;
			}
			for(ll i=0;i<g[x].size();i++){
				y = g[x][i];
				if(vis[y])continue;
				if(now[y]>w[x][i]){
					now[y] = w[x][i];
					noww[y] = 0;
					pq.push({-now[y],y});
				}
			}
			for(ll i=1;i<=k;i++){
				if(vis[i+n])continue;
				if(now[i+n]>dis[i][x]){
					now[i+n] = dis[i][x];
					noww[i+n] = 0;
					pq.push({-now[i+n],i+n});
				}
			}
		}else{
			x -= n;
			for(ll i=1;i<=n;i++){
				if(vis[i])continue;
				if(now[i]>dis[x][i]){
					noww[i] = x;
					now[i] = dis[x][i];
					pq.push({-now[i],i});
				}
			}
		}
	}
//	for(int i=1;i<=k;i++){
//		if(vis[i+n]){
//			if(kvis[i])continue;
//			ans-=now[i+n];
//		}
//	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin >> n >> m >> k;
	for(ll i=1;i<=m;i++){
		cin >> x >> y >> z;
		g[x].push_back(y);
		g[y].push_back(x);
		w[x].push_back(z);
		w[y].push_back(z); 
	}
	for(ll i=1;i<=k;i++){
		cin >> c[i];
		for(ll j=1;j<=n;j++)cin >> dis[i][j]; 
	}
	prim();
	cout << ans << endl;
	return 0;
}
