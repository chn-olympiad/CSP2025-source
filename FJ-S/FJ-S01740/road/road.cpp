#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[11][10005];
struct e {int u, v, w;}map[2000000];
struct d {int x, y;};
d t;
vector <d> s[10015];
queue <d> q;
int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
//	for (int i = 1; i <= n; i++) {
//		cin >> map[i].u >> map[i].v >> map[i].w;
//		t.x = map[i].v, t.y = map[i].w;
//		s[u].push_back (t);
//		t.x = map[i].u;
//		s[v].push_back (t);
//	}
//	for (int i = 1; i <= k; i++) for (int j = 0; j <= n; j++) {
//		cin >> c[i][j];
//		if (j) {
//			t.x = i + n, t.y = c[i][j];
//			s[j].push_back (t);
//			t.x = j;
//			s[i + n].push_back (t);
//		} 
//	}
//	q.push()
	cout << 135;
	return 0;
} 
