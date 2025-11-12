#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,u,v,x,y,d,ans,minn,c[10500][10500];
vector<int> ve[10050];

struct edge{
	int u,v;
}a[1000050];

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		cin >> u >> v >> x;
		ve[u].push_back(v);
		ve[v].push_back(u);
		c[u][v] = x;
		a[x].u = u;
		a[x].v = v;
	}
	cin >> x;
	for(int j = 1;j <= k;j ++){
		cin >> x;
	}
	for(int i = 1;i <= n;i ++){
		minn = 1e18;
		for(int j = 0;j < ve[i].size();j ++){
			for(int k = j + 1;k < ve[i].size();k ++){
				if(minn > c[i][j] + c[j][k]){
					x = j;
					y = k;
				}
			}
		}
		ans += minn;
		c[i][x] = 0;
		c[x][y] = 0;
	}
	cout << ans;
	return 0;
}
