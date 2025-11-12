#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647 //9223372036854775807
using namespace std;

inline int rd() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

vector <int> p[5];
int a[100005][5], cnt[5], c;

bool cmp(int x, int y) {
	int X = max(a[x][(c + 1) % 3], a[x][(c + 2) % 3]) - a[x][c];
	int Y = max(a[y][(c + 1) % 3], a[y][(c + 2) % 3]) - a[y][c];
	return X > Y;
}
void solve() {
	int n = rd(), sum = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 3; j++) a[i][j] = rd();
	p[0].clear(), p[1].clear(), p[2].clear();
	for(int i = 1; i <= n; i++) {
		if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) p[0].push_back(i), sum += a[i][0];
		else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) p[1].push_back(i), sum += a[i][1];
		else if(a[i][2] >= a[i][0] && a[i][2] >= a[i][1]) p[2].push_back(i), sum += a[i][2];
	}
	for(int k = 0; k < 3; k++) if(p[k].size() > n / 2) {
		c = k;
		int t = p[k].size() - n / 2;
		sort(p[k].begin(), p[k].end(), cmp);
		for(int x : p[k]) {
			sum += max(a[x][(c + 1) % 3], a[x][(c + 2) % 3]) - a[x][c];
			t--;
			if(!t) break;
		}
	}
	cout << sum << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for(int _ = rd(); _--; ) solve();
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

*/

