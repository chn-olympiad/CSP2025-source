#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
constexpr int maxn = 2e5 + 10, maxS = 5e6 + 10;
constexpr int MOD = 998244353 + 7, BASE = 13331;
int s[maxn];
unordered_map <int, int> w;
struct H {
	vector <int> f, qp; int M, B, N;
	void initf (int NN, const int mod, const int base, bool opt) {
//		cout << NN << " " << mod << " " << base << '\n';
		M = mod, B = base, N = NN; f.resize(NN + 10); f[0] = 0;
		for (int i = 1; i <= NN; i ++) {
			f[i] = (1ll * f[i - 1] * base % mod + s[i]) % mod;
//			cout << i << " : " << f[i] << '\n';
		} qp.resize(NN + 5); qp[0] = 1;
		for (int i = 1; i <= NN; i ++) {
			qp[i] = 1ll * qp[i - 1] * base % mod;
		}
//		cout << "TTT";
		if (opt == 1) w[f[NN]] ++;
//		cout << f[NN] << " : " << w[f[NN]] << '\n';
	}
	int Q (int l, int r) {
		return (f[r] + M - (1ll * f[l] * (r - l + 1) % M)) % M;
	}
} hh[maxn];
void solve (int id, string S, string T) {
	int L = -1, R = -1, len = S.size();
//	cout << id << '\n';
	for (int i = len - 1; i >= 0; i --) {
		if (S[i] != T[i]) {
			R = i;
			break;
		}
	}
	for (int i = 0; i < len; i ++) {
		if (S[i] != T[i]) {
			L = i;
			break;
		}
	} if (L == -1 && R == -1) return;
//	cout << id << " : ";
//	cout << "[, ] : " << L << " " << R << '\n';
	for (int i = L; i <= R; i ++) {
		s[i - L + 1] = (1ll * (S[i] - 'a') + (T[i] - 'a')) % MOD;
//		cout << s[i - L + 1] << ' ';
	}
//	cout << '\n';
//	cout << L << " " << R << '\n';
//	cout << id << "Hash : ";
	hh[id].initf(R - L + 1, MOD, BASE, 1);
}
int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
//	cout << n << ' ' << q << '\n';
	for (int i = 1; i <= n; i ++) {
		string S, T; cin >> S >> T;
//		cout << "ID : " << i << '\n';
		solve(i, S, T);
	}
	for (int i = 1; i <= q; i ++) {
		string S, T; cin >> S >> T;
		int len = S.size();
		int L = -1, R = -1;
		for (int i = len - 1; i >= 0; i --) {
			if (S[i] != T[i]) {
				R = i;
				break;
			}
		}
		for (int i = 0; i < len; i ++) {
			if (S[i] != T[i]) {
				L = i;
				break;
			}
		}
//		cout << L << " " << R << '\n' << "SSS : ";
		for (int i = L; i <= R; i ++) {
			s[i - L + 1] = (1ll * (S[i] - 'a') * BASE + (T[i] - 'a')) % MOD;
//			cout << s[i - L + 1] << ' ';
		} 
//		cout << '\n'; 
		hh[n + 1].initf(R - L + 1, MOD, BASE, 0);
//		cout << "last f : " << hh[n + 1].f[R - L + 1] << '\n';
		w[hh[n + 1].f[R - L + 1]] ++;
		cout << w[hh[n + 1].f[R - L + 1]] - 1 << '\n';
		w[hh[n + 1].f[R - L + 1]] --;
	}
	return 0;
}
