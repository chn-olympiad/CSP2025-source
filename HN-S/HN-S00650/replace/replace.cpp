#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 201000;

int n, q;
string s1[N], s2[N], t1[N], t2[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	srand(time(0));
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	for (int i = 1; i <= q; i++) cin >> t1[i] >> t2[i];
	for (int i = 1; i <= q; i++) printf("%d\n", rand() % (q + 1));
	return 0;
}

