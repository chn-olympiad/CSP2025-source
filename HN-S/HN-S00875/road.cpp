#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;
struct node{
	int u,v,w;
	bool operator < (const node &x) const {
		return w > x.w;
	}
};
bool b[N];
int n,m,k,ua,va,wa,ans,root,f[N],c[20],a[20][N];
priority_queue<node> s;
vector<node> q[N];
int find(int x){
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) cin >> c[i];
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	int minn = 1e9;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++){
		cin >> ua >> va >> wa;
		q[ua].push_back({ua,va,wa});
		q[va].push_back({va,ua,wa});
		if (wa < minn){
			minn = wa;
			root = ua;
		}
	}
	if (k == 0){
		int num = 1;
		for (int i = 0; i < q[root].size(); i++)
			s.push(q[root][i]);
		while (num < n){
			int u = s.top().u, v = s.top().v, w = s.top().w;
			s.pop();
			int fau = find (u), fav = find (v);
			if (fau != fav){
		    	b[u] = b[v] = 1;
				for (int i = 0; i < q[v].size(); i++){
					if (!b[q[v][i].v]) s.push(q[v][i]);
				}
				f[fav] = fau;
				ans += w;
				num++;
			}
		}
		cout << ans;
	}	
	else cout << 0;
	return 0;
}
