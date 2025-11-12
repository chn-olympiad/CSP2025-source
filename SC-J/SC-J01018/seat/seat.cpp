#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define MAXN 15
#define MAXM 15
#define pii pair<int, int>

int n, m;
int a[MAXN * MAXM];
bool cmp(int a, int b) {
	return a > b;
}
int di[2] = {+1, -1};

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) 
		cin >> a[i];
	int R = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int x = 1, y = 1, d = 0, curr = 1;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[curr] == R) {
				cout << y << ' ' << x << endl;
				return 0;
			}
			++curr;
			if (j != n)
				x += di[d % 2];
		}
		++y;
		++d;
	}
	return 0;
}