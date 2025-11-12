#include<bits/stdc++.h>
using namespace std;
struct str {
	string a, b;
} repe[200000 + 10];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; ++ i) {
		string a, b;
		cin >> a >> b;
		repe[i] = {a, b};
	}
	for(int i = 0; i < q; ++ i) {
		string a, b;
		cin >> a >> b;
		int ans = 0;
		printf("%d\n", ans);
	}
	return 0;
}
