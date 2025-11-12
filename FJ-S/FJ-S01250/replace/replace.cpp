#include <iostream>
#include <cstdio>
using namespace std;
int n, q, pos, ans;
string s1[200005], s2[200005], t1, t2, t3;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (register int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (register int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		ans = 0;
		for (int j = 1; j <= n; j++) {
			pos = t1.find(s1[j]);
			if (pos != -1) {
				t3 = t1;
				t3.replace(pos, s1[j].size(), s2[j]);
				if (t3 == t2)  ans++;
			}
		}
		printf("%d\n", ans);
	}
//	fclose(stdin); fclose(stdout);	
	return 0;
}
