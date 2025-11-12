#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
struct node{
	ll las,w;
};
vector<node> v[10020];
ll dis[10020];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= m;i++){
		ll x,y,z;
		cin >> x >> y >> z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
		
	}
	for(int i = 1;i <= k;i++){
		ll x,y;
		cin >> x;
		for(int j = 1;j <= n;j++){
			cin >> y;
			v[n + i].push_back({i,y});
			v[i].push_back({n + i,y});
		}
	}
	ll nw = 1;
	dis[1] = 0;
	for(int i = 1;i <= n + k;i++){
		for(int j = 0;j < v[i].size();j++){
			dis[v[i][j].las] = min(dis[v[i][j].las],dis[i] + v[i][j].w);
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n + k;i++){
		ans += dis[i];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

