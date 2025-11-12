#include<bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
#define rg register
#define vi std::vector<int>
#define L(i, a, b) for (rg int i = (a); i <= (b); i++)
#define R(i, a, b) for (rg int i = (a); i >= (b); i--)
#define rep(i, a) for (rg auto i : (a))
const int N = 3e5 + 5, M = 21, p = 1e9 + 7, inf = 8e18;
namespace zrh{
	int n, m, c[N], P[N]; string s;
	il void slv(){
		std::cin >> n >> m >> s, s = " " + s; L(i, 1, n) std::cin >> c[i];
		if (n <= 10){
			int ans = 0;
			L(i, 1, n) P[i] = i;
			do{
				int cur = 0, cnt = 0;
				L(i, 1, n){
					if (cur >= c[P[i]]) cur++;
					else{
						if (s[i] == '1') cnt++;
						else cur++;
					}
				}
				if (cnt >= m) ans++;
			}while(next_permutation(P + 1, P + n + 1));
			std::cout << ans;
			return ;
		}
	}
} signed main(){
	freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	return zrh::slv(), 0;
}
