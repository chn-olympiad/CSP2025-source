//GZ-S00306 贵阳市云城中学 王乾隆
#include <bits/stdc++.h>
#define X first
#define Y second
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = double;
using pii = pair<int, int>;
constexpr int maxn = 2e5 + 10, L = 6e6 + 10, bs = 519, mod = 998244353;
int n, Q; string S1[maxn], S2[maxn], t1, t2; char s1[L + 50], s2[L + 50], t3[L + 50]; int p = 0;
ull hs1[L], hs2[L], ht1[L], ht2[L], bp[L];
inline ull H(ull* h, int l, int r) {
	return h[r] - h[l - 1] * bp[r - l + 1];
}
void solve() {
	/*
	1 代表不同 
	0011001000
	0000000000
	在 s1 中查找 11001，然后在对应的位置把 s2 补上
	需要哈希 
	*/ 
	cin >> n >> Q;
	s1[0] = s2[0] = '*'; 
	rep(i, 1, n) {
		cin >> S1[i] >> S2[i];
		for (int j = 0; j < S1[i].size(); j++) {
			++p; s1[p] = S1[i][j]; s2[p] = S2[i][j];
		}
		++p; s1[p] = '*', s2[p] = '*';
	}
	bp[0] = 1;
	rep(i, 1, p) {
		hs1[i] = hs1[i - 1] * bs + s1[i];
		hs2[i] = hs2[i - 1] * bs + s2[i];
	}
	rep(i, 1, L - 1) bp[i] = bp[i - 1] * bs;
	// cout << p << " " << H(hs1, 1, 2) << " "<< H(hs2, );
	// exit(0);
	// 然后算前缀哈希值，当匹配到 
	// cout << s1 << "\n" << s2 << "\n";
	while (Q--) {
		int ans = 0;
		cin >> t1 >> t2; t1 = '\0' + t1, t2 = '\0' + t2; int k = t1.size() - 1;
		rep(i, 1, k) { 
			ht1[i] = ht1[i - 1] * bs + t1[i];
			ht2[i] = ht2[i - 1] * bs + t2[i];
		}
		int l = 1, r = k;
		while (t1[l] == t2[l]) ++l;
		while (t1[r] == t2[r]) --r;
		ull W = H(ht1, l, r); int len = r - l + 1; int pe = 1, nt = 1;
		rep(i, 1, p) {
			if (s1[i] == '*') pe = nt = i + 1;
			while (s1[nt + 1] != '*') ++nt;
			int now = nt - pe + 1; // 当前 s 的长度 
			int u = i - len + 1;
			if (u >= pe && H(hs1, u, i) == W) {
				// cout << l << " " << r << " " << l - u + pe << " " << r + nt - i << "\n"; exit(0);
				 // 在 s1 的 [u, i] 区间上，找到了 [l, r] 这段 t1
				 // 对齐就是将 s2 跟 [l + u - pe, r + nt - i] 的 t2 比较
				if (H(hs2, pe, nt) == H(ht2, l - u + pe, r + nt - i)) ++ans; 
			}
		} 
		cout << ans << "\n";
	}
}
int main() {
 	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
/* 
找到所有 b 的位置
t1 的 b 在 P1 位置，t2 的 b 在 P2 位置

aaaaaabaaa
aabaaaaaaa

考虑所有包含 aaaab 的 s1

这个简单计数即可 

它们的 s2 是什么，要求它们是把 b 移动了相同的距离

b 的变化量恰好为 r - l 的 

问题转化为二维数点 

int q[maxn], hd = 1, tl = 0, tot = 0, t[maxn][27], fa[maxn];
void bd() {
	// 先构建 trie 再构建 ACAM 
	rep(i, 1, n) {
		rep(j, 0, (int)s[i].size() - 1) t[]
	}
}
一个显然的做法是找到 t1 和 t2 的 LCP 和 LCS
s 和 s 之间的子串关系就很重要

考虑 

如果有 fa[u], t[u][c] = t[fa[u]][c]
否则 
00000111000011000
00000000000000000 
 
相当于查找有多少个包含子串 1110000111，且除了该子串，第二维对应位置也和 t 相等 

*/
/*
先分隔符给全体 s1 跑一遍 KMP
然后用 t1 跟 t2 的子串，在这堆 s1 上面跑匹配，

于是至少有一个 q*|L1| 的做法，能有一半分 


我们显然有一个 2^k * mlogn 的做法
接下来考虑怎么规避掉二进制枚举乡镇改造的复杂度
哦也有可能复杂度是 2^k * n，这时候我们可以接受
考虑先不用任何额外边，搞出最小生成树
把最小生成树的边跟额外边塞一起跑个最小生成树
注意到有些额外边是没有用的 
复杂度 O(mlogn + 2^k * n * k * a(n))
考虑怎么去掉这个 k
现在我们不考虑这个树边，考虑这几个乡镇自己之间跑一个最小生成树

实际上可以对这若干个乡镇跑一个传递闭包，然后把它们连起来

这里复杂度实际上可以 O(n + k) 

2^k * k * n *  
卡卡常可以通过 
先贪一遍
令 c 是最多的出现的，按新贡献分别调整到 b 和 a
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/


