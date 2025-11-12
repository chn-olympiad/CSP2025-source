#include <bits/stdc++.h>
#define GXOI ioxg
using namespace std;
const int N = 2e3 + 5;
int n, q, ans;
string s1[N], s2[N];
int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
		cin >> s1[i] >> s2[i];
	for (int i = 1; i <= q; i ++) {
		string t1, t2;
		cin >> t1 >> t2;
		ans = 0;
		for (int j = 1; j <= n; j ++) {
			//cout << "j" << endl;
			//cout << t1 << " " << t2 << endl;
			string q1 = t1;
			string q2 = t2;			
			int len = s1[j].size () - 1;
			for (int k = 0; k < (int)t1.size();k ++) {
				//cout << "k" << endl;
				int l = k;
				int r = k + len;
				if (r > (int)t1.size())
					break;
				int flag = 0;
				for (int x = l; x <= r; x ++) {
					//cout << "x" << endl;
					if (q1[x] != s1[j][x - l]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					//cout << "HAPPY" << endl;
					for (int x = l; x <= r; x ++)
						q1[x] = s2[j][x - l];
					//cout << q1 << endl;
				}
				if (q1 == q2) {
					//cout << q1 << " " << q2 <<endl;
					ans ++;					
				}
				if (flag == 0)
					break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
