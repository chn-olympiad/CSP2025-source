#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int n, m, k;
long long a[MAXN][MAXN], c[15], p[15][MAXN];
struct Node{
	int data, pos;
};
template<typename Node>
    struct cmp : public binary_function<Node, Node, bool>
    {
    	bool operator()(const Node& __x, const Node& __y){
			return __x.data > __y.data; 
		}
    };

priority_queue<Node, vector<Node>, cmp<Node> > q;
bool vis1[MAXN], vis2[MAXN][MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(a, 0x7f, sizeof(a));
	for(int i = 1, u, v, w; i <= m; i++){
		cin >> u >> v >> w;
		a[u][v] = a[v][u] = w;
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++) cin >> p[i][j];
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(c[i] + p[i][j] + p[i][k] < a[j][k]) a[j][k] = c[i] + p[i][j] + p[i][k];
			}
		} 
	}
	vis1[1] = 1;
	for(int i = 2; i <= n; i++){
		q.push({a[1][i],i});
		vis2[1][i] = vis2[i][1] = 1;
	}
	long long ans = 0;
	int cnt = 1;
	while(cnt < n){
		Node tmp = q.top();
		q.pop();
		if(vis1[tmp.pos] == 1) continue;
		vis1[tmp.pos] = 1;
		ans += 1ll * tmp.data;
		cnt++;
		for(int i = 1;i <= n;i++){
			if(i != tmp.pos && vis1[i] == 0 && vis2[i][tmp.pos] == 0){
				q.push({a[tmp.pos][i],i});
				vis2[tmp.pos][i] = vis2[i][tmp.pos] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}
