#include <bits/stdc++.h>
using namespace std;

int n, q;
string s[200010][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	freopen("replace2.in", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 1 ; i <= n ; i++)
		cin >> s[i][0] >> s[i][1];
	for (string t1, t2 ; q-- ; ) {
		cin >> t1 >> t2;
		int m = t1.size(), m2 = t2.size();
		t1 = " " + t1, t2 = " " + t2;
		if (m != m2) {
			puts("0");
			continue;
		}
		int res = 0;
		for (int l = 1 ; l <= m ; l++)
			for (int r = l ; r <= m ; r++) {
				bool flag = true;
				for (int i = 1 ; i < l && flag ; i++)
					flag &= (t1[i] == t2[i]);
				for (int i = r + 1 ; i <= n && flag ; i++)
					flag &= (t1[i] == t2[i]);
				if (!flag) continue;
				for (int id = 1 ; id <= n ; id++)
					if ((int)s[id][0].size() == r - l + 1) {
//						cout << l << " " << r << " " << id << "??" << endl;
						flag = true;
						for (int i = l ; i <= r && flag ; i++)
							flag &= (s[id][0][i - l] == t1[i] && s[id][1][i - l] == t2[i]);
						res += flag;
//						if (flag) cout << l << " " << r << " " << id << endl;
					}
			}
		printf("%d\n", res);
	}
	return 0;
}
