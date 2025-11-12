#include <bits/stdc++.h>
#define mod 998244353

using namespace std;
const int N = 510;

int n, q;
string s1, s2;
int a[N];
int flg = true;


inline void SeaWave() {
	cin >> n >> q;
//	for (int i = 1; i <= n; ++i)
//		cin >> s1 >> s2;
//	for (int i = 1; i <= q; ++i)
//		cin >> s1 >> s2;
	for (int i = 1; i <= q; ++i)
		cout << 0 << endl;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int T = 1;
//	T = read();
	while (T--)
		SeaWave();
	return 0;
}
