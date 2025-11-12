#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 10, mod = 998244353;

int n, m;
char s[maxn];
int a[maxn];

int p[maxn];
int ans;
bool check() {
	int num = 0, fail = 0;
	for (int i = 1; i <= n; i++)
	{ 
		if (s[i] == '0') { fail++; continue; } 
		if (fail >= a[p[i]]) { fail++; continue; }
		num++;
	}
	return num >= m; 
}
void solve() {
	for (int i = 1; i <= n; i++) p[i] = i;
	do {
		if (check()) ans++;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans << "\n";
}
int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	cin >> (s + 1);
	int flg = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	solve(); 
	return 0;
}