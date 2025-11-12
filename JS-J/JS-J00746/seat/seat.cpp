#include <bits/stdc++.h>
using namespace std;

#define problem_id "seat"
#define int int64_t
#define pii pair<int64_t, int64_t>
#define vec(ty) vector<ty>
#define arr(ty, siz) array<ty, siz>
#define map(tk, tv) map<tk, tv>

int n, m;
arr(int, 105) score;






// fstream fin, fout;
signed main() {
	// fin.open(problem_id".in");
	// fout.open(problem_id".out");
	// #define cin fin
	// #define cout fout

	freopen(problem_id".in", "r", stdin);
	freopen(problem_id".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n >> m;
	for (int i=1; i<=n*m; i++) {
		cin >> score.at(i);
	}
	int a1 = score.at(1);
	sort(next(begin(score)), next(begin(score), n*m), [](int a, int b) { return a>b; });
	int idx = find(next(begin(score)), next(begin(score), n*m), a1) - next(begin(score)) + 1;
	// for (int i=1; i<=n*m; i++) {
	// 	cout << score.at(i) << " ";
	// }
	// cout << '\n';

	int col = idx/n+1;
	cout << col << " ";
	if (col & 1) {
		cout << (idx - (col-1)*n);
	}
	else {
		cout << (col*n - idx + 1);
	}

	// cout << idx;




	// #undef cin
	// #undef cout
	return 0;
}
// #undef int

/*

CSP-J RP++
CSP-J RP++
CSP-J RP++

Nina Iseri保佑我

*/