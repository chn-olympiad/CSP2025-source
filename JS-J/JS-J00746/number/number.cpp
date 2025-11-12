#include <bits/stdc++.h>
using namespace std;

#define problem_id "number"
#define int int64_t 	
#define pii pair<int64_t, int64_t>
#define vec(ty) vector<ty>
#define arr(ty, siz) array<ty, siz>
#define map(tk, tv) map<tk, tv>

char c;
vec(int) num;






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



	while (cin >> c) {
		if (isdigit(c)) {
			num.push_back(c-'0');
		}
	}
	sort(num.begin(), num.end(), [](int a, int b) { return a>b; });
	for (const auto& i: num) {
		cout << i;	
	}



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