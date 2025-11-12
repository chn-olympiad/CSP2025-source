#include <bits/stdc++.h>
using namespace std;

#define problem_id "polygon"
#define int int64_t
#define pii pair<int64_t, int64_t>
#define vec(ty) vector<ty>
#define arr(ty, siz) array<ty, siz>
#define map(tk, tv) map<tk, tv>


int n;
arr(int, 5005) a;

// int res;
const int MOD = 998244353;

// map(, int) mem;
vec(int) collect;
map(vec(int), bool) reg;
int dfs(int id, int mx, int total, int cnt) {
	if (id > n) return 0;
	// if (mem[{id, mx, total, cnt}]) {
	// 	return mem[{id, mx, total, cnt}];
	// }
	int res = 0;
	if (cnt >= 3 && total > 2*mx && !reg[collect]) {
		// cout << id << " " << mx << " " << total << " " << cnt << endl;
		reg[collect] = true;
		res = (res+1)%MOD;
	}
	collect.push_back(id+1);
	res = (res + dfs(id+1, max(mx, a.at(id+1)), total+a.at(id+1), cnt+1)%MOD)%MOD;
	collect.pop_back();
	res = (res + dfs(id+1, mx, total, cnt)%MOD)%MOD;
	return res;
}



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

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a.at(i);
	}

	cout << dfs(0, 0, 0, 0);




	// #undef cin
	// #undef cout
	return 0;
}

/*

CSP-J RP++
CSP-J RP++
CSP-J RP++

Nina Iseri保佑我

*/