/*
一家公司，共有 n 人前来应聘，编号为 1 ～ n。
小 Z 和小H 希望录用至少 m 人。
小 H 是面试官，将在接下来 n 天每天面试一个人。
小 Z 负责决定应聘人前来面试的顺序。
具体地，小 Z 可以选择一个 1 ～ n 的排列 p，然后在第 i (1 ≤ i ≤ n) 天通知编号为 pi 的人前来面试。
小 H 准备了 n 套难度不一的面试题。
 n 个前来应聘的人水平大致相同，因此对于同一套题，所有人的作答结果是一致的。
 具体地，第 i (1 ≤ i ≤ n) 天的面试题的难度为 si ∈ {0, 1}，其中 si = 0 表示这套题的难度较高，没有人能够做出；
 si = 1 表示这套题的难度较低，所有人均能做出。
 小 H 会根据面试者的作答结果决定是否录用，即如果面试者没有做出面试题，则会拒绝，否则会录用。
然而，每个人的耐心都有一定的上限，如果在他面试之前未录用的人数过多，则他会直接放弃参加面试。
具体地，编号为 i (1 ≤ i ≤ n) 的人的耐心上限可以用非负整数 ci
描述，若在他之前已经有不. 少. 于.ci 人被拒绝或放弃参加面试，则他也将放弃参加面试。
小 Z 想知道一共有多少种面试的顺序 p 能够让他们录用至少 m 人。
你需要帮助小Z 求出，能够录用至少 m 人的排列 p 的数量。
由于答案可能较大，你只需要求出答案对 998, 244, 353 取模后的结果。
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int NN = 510, Mod = 998244353;
int a[NN], c[NN];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	string s; cin >> s;
	for(int i = 1; i <= n and cin >> c[i]; i ++);
	int ans = 0;
	if(n <= 10) {
		for(int i = 1; i <= n; i ++) a[i] = i;
		do {
			int cnt = 0, res = 0;
			for(int i = 1; i <= n; i ++) {
				if(s[i - 1] == '0' || cnt >= c[a[i]]) cnt ++;
				else res ++;
			}
			if(res >= m) ans ++;
		} while(next_permutation(a + 1, a + 1 + n));
	}
	return cout << ans, 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
