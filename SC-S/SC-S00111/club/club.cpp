#include<bits/stdc++.h>
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
int t, n, b[100001], s[4];
vector<vector<int>> v(4);
struct node{
	int x, t;
}a[100001][4];
bool cmp(node a, node b){
	return a.x > b.x;
}
bool cmp1(int u, int v){
	if(u == 1e9) return false;
	if(v == 1e9) return true;
	return a[u][b[u]].x - a[u][b[u] + 1].x < a[v][b[v]].x - a[v][b[v] + 1].x;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		int ans = 0; _for(i, 1, 3) v[i].clear(); s[1] = s[2] = s[3] = 0;
		_for(i, 1, n){
			_for(j, 1, 3) cin >> a[i][j].x, a[i][j].t = j;
			sort(a[i] + 1, a[i] + 4, cmp);
			node _a = a[i][1];
			b[i] = 1, s[_a.t]++, v[_a.t].push_back(i), ans += _a.x;
		}
		_for(k, 1, 6){
			int i = k;
			if(i > 3) i -= 3;
			if(s[i] > n / 2){
				sort(begin(v[i]), end(v[i]), cmp1);
				_for(j, 0, s[i] - n / 2 - 1){
					int _v = v[i][j];
					ans -= (a[_v][b[_v]].x - a[_v][++b[_v]].x);
					s[a[_v][b[_v]].t]++;
					v[a[i][b[_v]].t].push_back(_v), _v = 1e9;
				}
				s[i] -= n / 2;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}