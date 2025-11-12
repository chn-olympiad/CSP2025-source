#include <bits/stdc++.h>
using namespace std;
const int NR = 1e4 + 4;
int n, m, k, x, y, z, a[15][NR], c, ans, sum;
struct node{
	int u, v, w;
	/*bool operater<(const a){
		return *a;
	}*/
};
vector<node> g[NR];
/*void dijk(){
	//priority_queue<node, vector<node>, greater> >q;
	//q.push(1);
	
}*/
int main(){
  	freopen("road.in","r",stdin);
  	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		cin >> x >> y >> z;
		g[i].push_back({x, y, z});
		g[i].push_back({y, x, z});
		ans += z;
	}
	for(int i = 1;i <= k;i ++){
		cin >> c;
		sum = c;
		for(int j = 1;j <= n;j ++){
			cin >> a[i][j];
			sum += a[i][j];
		}
		ans = min(ans, sum);
	}
	cout << ans;
	return 0;
}

