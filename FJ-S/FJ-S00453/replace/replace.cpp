#include<bits/stdc++.h>
using namespace std;
string st[200005][2];
string q1, q2;
int n, q, cd, l, r, ans;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> st[i][0] >> st[i][1];
	while (q--) {
		ans = 0;
		cin >> q1 >> q2;
		cd = q1.length();
		l = 0, r = cd-1;
		while (l <= cd - 1) {
			if (q1[l] != q2[l]) break;
			l++;
		}
		while (r >= 0) {
			if (q1[r] != q2[r]) break;
			r--;
		}
		
		for (int i = 1; i <= n; i++) {
			int l1 = max ((int (1 + r - st[i][0].length())), 0);
			while (l1 <= min(l,int (cd-st[i][0].length()))) {
				int pd = 1;
				for (int l2 = 0; l2 <= (-1)+st[i][0].length(); l2++) {
					if (q1[l1+l2] != st[i][0][l2]||q2[l1+l2] != st[i][1][l2]) {
						pd=0;
						break;
					}
				}
				if (pd){
//					cout<<i<<" "<<l1<<endl;
					ans++;
				}
				l1++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
