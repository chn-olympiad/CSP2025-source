#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define per(i, r, l) for (int i = r; i >= l; i --)
#define int long long

using namespace std;
/*
退役好久了，连比赛里能不能用结构化绑定都不知道了 /kk
老了老了。。。 
感觉这次如果是以前的我或许可以过 t3 吧，感觉确实有点不简单Zzz
胡一下：
不妨认为替换的部分就是 a()b, a[]b
那么就要查询有多少对

() = x_k, [] = y_k

主要是忘记了字符串，虚树那几个黑盒是怎么搞的了，这个 L1 和 L2 还 tm 长的吓人，有一点点无语。
早知道复习一下了，联赛前在重温重温吧。
本质老头来了 sad 
afk tooo loonngg
 
*/ 
const int maxn = 2e3 + 5, mod = 998244353;

int T;
int n, q, len[maxn];
struct hash {
	int ky;
	vector<int> h, pw;
	void init(string x, int P) {
		h.clear(), pw.clear();
		h.push_back(0), pw.push_back(1);
		rep(i, 0, x.size() - 1) {
			h.push_back((h[i] * P + (int)(x[i] - 'a' + 1)) % mod);
			pw.push_back((pw[i] * P % mod));
		}
		ky = h.back();
	}
	int get_hash (int l, int r) {
		if (r < l) return 0; 
		return (h[r] - (h[l - 1] * pw[r - l + 1] % mod) + mod) % mod;
	}
} h1, h2, h3, h4, ha[maxn][2], hb[maxn][2];
signed main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	/**/
	cin >> n >> q;
	string a, b;
	rep(i, 1, n) {
		cin >> a >> b;
		len[i] = a.size();
		ha[i][0].init(a, 23), ha[i][1].init(a, 29);
		hb[i][0].init(b, 23), hb[i][1].init(b, 29);
	}
	while(q --) {
		cin >> a >> b;
		int ans = 0;
		h1.init(a, 23), h2.init(a, 29);
		h3.init(b, 23), h4.init(b, 29);	
		rep(i, 0, a.size() - 1) {
			rep(j, 1, n) {
				if (i + 1 >= len[j]){
					if (h1.get_hash(i - len[j] + 2, i + 1) == ha[j][0].ky 
					 && h2.get_hash(i - len[j] + 2, i + 1) == ha[j][1].ky
					 && h3.get_hash(i - len[j] + 2, i + 1) == hb[j][0].ky
					 && h4.get_hash(i - len[j] + 2, i + 1) == hb[j][1].ky
					 && h1.get_hash(1, i - len[j] + 1) == h3.get_hash(1, i - len[j] + 1)
					 && h1.get_hash(i + 2, a.size()) == h3.get_hash(i + 2, a.size())
					 && h2.get_hash(1, i - len[j] + 1) == h4.get_hash(1, i - len[j] + 1)
					 && h2.get_hash(i + 2, a.size()) == h4.get_hash(i + 2, a.size()))
				    ans ++;
				}	
			}
		}
		cout << ans << '\n';
	}
} 

