#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_map>
#include <bitset>
#define int long long
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull, ull> PII;
const int N = 5e6 + 10, M = 2e5 + 10, mod = 998244353;
bool Mst;
int n, m, c[N], f[1 << 18][20];
string S;
bool Med;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	ios::sync_with_stdio(0), cin.tie(0);
//	cerr << abs(&Mst - &Med) / 1048576.0 << "Mb\n";
	clock_t stt = clock();
	cin >> n >> m >> S, S = " " + S;
	for(int i = 1; i <= n; i ++) cin >> c[i];
	f[0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int s = 0; s < (1 << n); s ++) {
			if((int)__builtin_popcount(s) != i - 1) continue;
			for(int j = 0; j < i; j ++) {
				int val = f[s][j];
				if(!val) continue;
//				cout << s << ' ' << j << ' ' << val << '\n';
				for(int k = 1; k <= n; k ++) {
					if(s >> k - 1 & 1) continue;
					if(j >= c[k] || S[i] == '0') 
						(f[s | (1 << k - 1)][j + 1] += val) %= mod;
					else (f[s | (1 << k - 1)][j] += val) %= mod;
				}
			}
		}
	}
//			for(int j = 0; j <= n; j ++) 
//				cout << j << ' ' << f[(1 << n) - 1][j] << '\n';
	int ans = 0;
	for(int i = 0; i <= n - m; i ++) ans = (ans + f[(1 << n) - 1][i]) % mod;
	cout << ans << '\n';
	
	cerr << (1.0 * clock() - stt) / CLOCKS_PER_SEC << "s\n";
	
	return 0;
}
