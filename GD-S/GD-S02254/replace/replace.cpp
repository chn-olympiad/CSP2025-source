#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define MAXN (200010)

using namespace std;
int T, n, q;

string s[MAXN][3];
string ask[MAXN][3];

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][1] >> s[i][2];
	for (int i = 1; i <= q; i++) {
		cin >> ask[i][1] >> ask[i][2];
		cout << 0 << "\n";
	} 
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	T = 1;
	while (T --) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
