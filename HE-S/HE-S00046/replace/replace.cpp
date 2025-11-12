#include <bits/stdc++.h>
#define _for(i,a,b) for (int i = a; i <= b; ++i)
#define for_(i,a,b) for (int i = a; i >= b; --i)
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair <int, int> pii;
typedef std::pair <ll, ll> pll;
const int N = 2e5 + 10, LN = 5e6 + 10, P = 998244353;
const ll inf = 1ll << 60;
namespace IO {
	int rnt () {
		int x = 0, w = 1; char c = getchar ();
		while (!isdigit (c)) { if (c == '-') w = -1; c = getchar (); }
		while (isdigit (c)) x = x * 10 + c - '0', c = getchar ();
		return x * w;
	}
}
namespace SEGMENT_TREE {
	class Node {
	private:
		Node* ls;
		Node* rs;
		int l, r;
		int sum;

	public:
		Node (int l, int r) : l (l), r (r), sum (0) {
			if (l != r) {
				int mid = (l + r) / 2;
				ls = new Node (l, mid);
				rs = new Node (mid + 1, r);
			}
		}
		void Upd (int L, int R, int w) {
			if (L <= l && r <= R)
				sum += w;
			else {
				int mid = (l + r) / 2;
				if (L <= mid)
					ls->Upd (L, R, w);
				if (mid < R)
					rs->Upd (L, R, w);
			}
			return;
		}
		int Que (int x) {
			if (l == r)
				return sum;
			else {
				int mid = (l + r) / 2;
				if (x <= mid)
					return ls->Que (x) + sum;
				else
					return rs->Que (x) + sum;
			}
		}
	};
}
namespace SOLVE {
	using namespace IO;
	using namespace SEGMENT_TREE;
	int n, q, F[N][2], G[N][2], ans[N];
	char S[LN], T[LN], tmp[LN];
	class Trie {
	public:
		int tot, nxt[LN][26], cnt, dfn[LN][2];
		int Ins (int R, char* S, int m) {
			int p = R;
			_for (i, 0, m - 1) {
				int c = S[i] - 'a';
				if (!nxt[p][c])
					nxt[p][c] = ++tot;
				p = nxt[p][c];
			}
			return p;
		}
		void DFS (int u) {
			dfn[u][0] = ++cnt;
			_for (c, 0, 25) if (nxt[u][c])
				DFS (nxt[u][c]);
			dfn[u][1] = cnt;
			return;
		}
	} mid, pre, suf;
	std::vector <int> U[LN][2];
	void In () {
		n = rnt (), q = rnt ();
		_for (i, 1, n) {
			scanf ("%s%s", S + 1, T + 1);
			int m = strlen (S + 1), L = 1, R = m;
			_for (j, 1, m) if (S[j] != T[j]) { L = j; break; }
			for_ (j, m, 1) if (S[j] != T[j]) { R = j; break; }
			int p = mid.Ins (0, S + L, R - L + 1);
			p = mid.Ins (p, T + L, R - L + 1);
			_for (j, 1, L - 1) tmp[j] = S[L - j];
			F[i][0] = pre.Ins (0, tmp + 1, L - 1);
			F[i][1] = suf.Ins (0, S + R + 1, m - R);
			U[p][0].emplace_back (i);
		}
		_for (i, 1, q) {
			scanf ("%s%s", S + 1, T + 1);
			int m = strlen (S + 1), L = 1, R = m;
			_for (j, 1, m) if (S[j] != T[j]) { L = j; break; }
			for_ (j, m, 1) if (S[j] != T[j]) { R = j; break; }
			int p = mid.Ins (0, S + L, R - L + 1);
			p = mid.Ins (p, T + L, R - L + 1);
			_for (j, 1, L - 1) tmp[j] = S[L - j];
			G[i][0] = pre.Ins (0, tmp + 1, L - 1);
			G[i][1] = suf.Ins (0, S + R + 1, m - R);
			U[p][1].emplace_back (i);
		}
		return;
	}
	void Solve () {
		pre.DFS (0), suf.DFS (0);
		Node* H = new Node (1, suf.cnt);
		_for (p, 0, mid.tot) {
			if (U[p][0].empty ()) continue;
			if (U[p][1].empty ()) continue;
			std::vector <pii> off;
			for (auto j : U[p][0]) {
				off.emplace_back (pre.dfn[F[j][0]][0], -j);
				off.emplace_back (pre.dfn[F[j][0]][1] + 1, -j);
			}
			for (auto j : U[p][1])
				off.emplace_back (pre.dfn[G[j][0]][0], j);
			std::sort (off.begin (), off.end ());
			for (auto t : off) {
				int j = t.second;
				if (j > 0)
					ans[j] = H->Que (suf.dfn[G[j][1]][0]);
				else {
					j = -j;
					int w = (t.first == pre.dfn[F[j][0]][0]) ? 1 : -1;
					H->Upd (suf.dfn[F[j][1]][0], suf.dfn[F[j][1]][1], w);
				}
			}
		}
		return;
	}
	void Out () {
		_for (i, 1, q)
			printf ("%d\n", ans[i]);
		return;
	}
}
int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	SOLVE::In ();
	SOLVE::Solve ();
	SOLVE::Out ();
	return 0;
}