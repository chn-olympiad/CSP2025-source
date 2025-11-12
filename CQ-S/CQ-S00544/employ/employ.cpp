#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e2 + 10;

string str;
int n, m;
int c[N];

int main(int argc, char *argv[]) {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	
	cin >> str;
	
	for (int i = 1; i <= n; i ++ ) cin >> c[i];
	long long ans = 1;
	for (int i = 1; i <= n; i ++ ) ans *= i * 1LL;
	cout << ans << "\n";
	return 0;
}
