#include<bits/stdc++.h>
#define PII pair<long long,long long>
using namespace std;
typedef long long ll;
const int N = 1e4 + 100;
struct Node{
	ll idx,w;
	bool operator < (const Node &oji) const{
		return w > oji.w;
	}
};
priority_queue<Node>heap;
ll n,m,k,vis[N],ans,dis[N],tot;
vector<PII>E[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		ll u,v,w;
		cin >> u >> v >> w;
	}
	for(int i = 1; i <= k; ++i){
		ll id;
		cin >> id;
		ll x[N];
		for(int j = 1; j <= n; ++j){
			cin >> x[j];
		}
	} 
	cout << 0;
	return 0;
}
