#include<bits/stdc++.h>
using namespace std;
//#define int long long
//const int mod=

int n, q;
string s[200005][2];


vector<int>kmp[200005][2];
vector<int>sum_1[2];

//map<int, int >fun;


void kmp_get(int i_, int k_) {
	kmp[i_][k_].push_back(0);
	for (int i = 1; i < s[i_][k_].size(); i++) {
		int k = kmp[i_][k_][i - 1];
		while (k >= 0 && s[i_][k_][k] != s[i_][k_][i]) k = (k ? kmp[i_][k_][k - 1] : -1);
		kmp[i_][k_].push_back(k + 1);
	}
	return;
}

void kmp_work(string s1, int i_, int k_) {
	for (int i = 0, k = 0; i < s1.size();) {
		if (s1[i] == s[i_][k_][k]) {
			if (k + 1 == (int)s[i_][k_].size()) {
				sum_1[k_].push_back(i);
				k = kmp[i_][k_][k];
			} else k++;
			i++;
		} else k ? k = kmp[i_][k_][k - 1] : i++;
	}
}

void work_1() {
	for (int i = 1; i <= n; i++)
		for (int k = 0; k < 2; k++)
			kmp_get(i, k);
	for (int op = 1; op <= q; op++) {
		string x, y;
		cin >> x >> y;
		int L = 0, R = (int)x.size() - 1;
		while (x[L] == y[L]) L++;
		while (x[R] == y[R]) R--;
		int ans = 0;
		for (int _i_ = 1; _i_ <= n; _i_++) {
			sum_1[0].clear();
			sum_1[1].clear();
			kmp_work(x, _i_, 0);
			kmp_work(y, _i_, 1);
			for (int i = 0, k = 0; i < sum_1[0].size() && k < sum_1[1].size();) {
				int gi = sum_1[0][i];
				int gk = sum_1[1][k];
				if (gi == gk && gi >= R && gi - (int)s[_i_][0].size() < L) {
					ans++;
					break;
				}
				if (gi > gk) k++;
				else i++;
			}
		}
		printf("%d\n", ans);
	}
	return;
}

//void work_2() {
//	for (int i = 1; i <= n; i++) {
//		int l_1 = 0, l_2 = 0;
//		while (s[i][0][l_1] != 'b') l_1++;
//		while (s[i][1][l_2] != 'b') l_2++;
//		fun[l_2 - l_1] ++;
//	}
//	for (int op = 1; op <= q; op++) {
//		string x, y;
//		cin >> x >> y;
//		int l_1 = 0, l_2 = 0;
//		while (x[l_1] != 'b') l_1++;
//		while (y[l_2] != 'b') l_2++;
//
//	}
//	return;
//}

void work_p() {
	int Len = 0;
	for (int i = 1; i <= n; i++)
		Len += 2 * (int)s[i][0].size();
//	if (1LL * q * Len <= 5e8)
	work_1();
//	else work_2();
	return;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][0] >> s[i][1];
	work_p();

	return 0;
}
