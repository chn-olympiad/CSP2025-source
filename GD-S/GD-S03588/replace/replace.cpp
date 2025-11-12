#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int n, q;
string s[100001][2], t1, t2;
char a[5000005], b[5000005];
map<string, int> mp;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s%s", a, b);
		s[i][0] = a;
		s[i][1] = b;
	}
	for (int i = 1; i <= q; i++) {
		scanf("%s%s", a, b);
		t1 = a;
		t2 = b;
		if (t1.size() != t2.size()) {
			printf("0\n");
			continue;
		}
		int l = t1.size();
//		for (int j = 0; j < l; j++)
//			for (int k = j; k < l; k++)
		int st = 0, en = 0;
		bool f = true;
		for (int j = 0; j < l; j++) {
			if (t1[j] != t2[j]) {
				if (st && !en) {
					f = false;
					break;
				}
				st = j;
			} else {
				if (!en)
					en = j - 1;
			}
		}
		if (!en)
			en = l - 1;
		if (!f)
			printf("%d\n", 0);
		else {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				int L = s[j][0].size();
				for (int k = 0; k < l - L + 1; k++) {
					string g = t1;
					for (int p = k; p < k + L; p++)
						g[p] = s[j][0][p - k];
					if (g == t2)
						cnt++;
				}
			}
			printf("%d\n", cnt);
		}
	}
	//32475698
	//23475698
	return 0;
}
