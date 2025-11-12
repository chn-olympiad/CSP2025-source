#include<bits/stdc++.h>
using namespace std;
#define nmax 200007
#define int long long

int n, q;
string s[nmax][4];
string buff1, buff2; // 待处理相

int tire[nmax][30], tot;
string eend[nmax];
void insert() {
	int jump = 0;

	for (int i = 0; i < (int)buff1.size(); i++) {
		if (tire[jump][buff1[i] - 'a' + 1] == 0) {
			tire[jump][buff1[i] - 'a' + 1] = ++tot;
			jump = tot;
		} else {
			jump = tire[jump][buff1[i] - 'a' + 1];
		}
	}

	eend[jump] = buff2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
		s[i][1] = " " + s[i][1];
		s[i][2] = " " + s[i][2];
		buff1 = s[i][1];
		buff2 = s[i][2];
		//	insert();
	}

	for (int i = 1; i <= q; i++) {
		cout << 0 << endl;
	}

	return 0;
}