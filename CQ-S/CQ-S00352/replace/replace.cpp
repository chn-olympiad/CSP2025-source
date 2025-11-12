#include<bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
#define rg register
#define vi std::vector<int>
#define L(i, a, b) for (rg int i = (a); i <= (b); i++)
#define R(i, a, b) for (rg int i = (a); i >= (b); i--)
#define rep(i, a) for (rg auto i : (a))
const int N = 2e5 + 5, M = 21, p = 1e9 + 7, inf = 8e18;
namespace zrh{
	int n, q; string s[N][2]; map<pair<string, string>, int> c;
	il void slv(){
		std::cin >> n >> q; L(i, 1, n) std::cin >> s[i][0] >> s[i][1];
		int fl = 1;
		L(i, 1, n){
			rep(it, s[i][0]) fl &= (it == 'a' || it == 'b');
			rep(it, s[i][1]) fl &= (it == 'a' || it == 'b');
		}
		if (fl){
			map<pair<pair<int, int>, pair<int, int> >, int> c;
			L(i, 1, n){
				int c1 = 0, c2 = 0, L = (int)s[i][0].size() - 1;
				rep(j, s[i][0]){
					if (j == 'b') break;
					c1++;
				}
				rep(j, s[i][1]){
					if (j == 'b') break;
					c2++;
				}
				c[{{c1, L - c1}, {c2, L - c2}}]++;
			}
			L(_, 1, q){
				string t1, t2; std::cin >> t1 >> t2;
				if ((int)t1.size() != (int)t2.size()){ std::cout << "0\n"; continue; }
				int L = (int)t1.size(); t1 = " " + t1, t2 = " " + t2;
				int c1 = 0, c2 = 0, ans = 0;
				rep(j, t1){
					if (j == 'b') break;
					c1++;
				}
				rep(j, t2){
					if (j == 'b') break;
					c2++;
				}
				int d1 = L - 1 - c1, d2 = L - 1 - d2;
				L(e, 0, L - 1){
					ans += c[{{c1 + e, d1 + e}, {c2 + e, d2 + e}}];
				}
				std::cout << ans << "\n";
			}
			return ;
		}
		L(i, 1, n) c[{s[i][0], s[i][1]}]++;
		L(_, 1, q){
			string t1, t2; std::cin >> t1 >> t2;
			if ((int)t1.size() != (int)t2.size()){ std::cout << "0\n"; continue; }
			int L = (int)t1.size(); t1 = " " + t1, t2 = " " + t2;
			int p1 = 0, p2 = 0, ans = 0;
			L(i, 1, L){
				if (t1[i] != t2[i] && !p1) p1 = i;
				if (t1[i] != t2[i]) p2 = i;
			}
			L(i, 1, p1){
				L(j, p2, L){
					string y = t1.substr(i, j - i + 1), yy = t2.substr(i, j - i + 1); 
					ans += c[{y, yy}];
				}
			}
			std::cout << ans << "\n";
		}
	}
} signed main(){
	freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	return zrh::slv(), 0;
}
