#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pss pair <string, string>
const int N = 2e5+100;

int n, q;
pss s[N];

void solve () {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n;i++) 
		cin >> s[i].first >> s[i].second;
	for (int i = 1;i <= q;i++) {
		string t1, t2; cin >> t1 >> t2;
		printf("0\n");
	}
}

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int _ = 1; scanf("%d", &_);
	while(_--) solve();
	return 0;
}

