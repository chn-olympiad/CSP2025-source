#include <iostream>
#include <fstream>
using namespace std;
const int N = 510;
int n, m;
int s[N], c[N];
long long ans = 0;
bool b[N];

void dfs (int x, int bk, int sb, int tg) {
	if (x == n+1) {
		if (tg >= m) ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i]) continue;
		b[i] = 1;
		if (bk >= c[i] || sb >= c[i]) dfs(x+1, bk+1, sb, tg);
		else if (s[x] == 0) dfs (x+1, bk, sb+1, tg);
		else dfs(x+1, bk, sb, tg+1);
		b[i] = 0;
	}
}

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	cin >> n >> m;
	char ch;
	for (int i = 1; i <= n; i++) {
		cin >> ch; s[i] = ch-'0';
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(1, 0, 0, 0);
	cout << ans;
	return 0;
}
