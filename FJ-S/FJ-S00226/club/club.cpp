#include<bits/stdc++.h>
using namespace std;
int t;
struct cy {
	int b1, b2, b3;
};
bool cmp(cy x, cy y) {
	return x.b1 > y.b1;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, ans = 0;
		cy ch[1000005];
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> ch[j].b1 >> ch[j].b2 >> ch[j].b3;
		}
		int flag = 1;
		for (int j = 1; j <= n; j++) {
			if (ch[i].b3 != 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			for (int j = 1; j <= n; j++) {
				if (ch[i].b2 != 0) {
					flag = 2;
					break;
				}
			}
		}
		if (flag == 1) {
			sort(ch+1,ch+1+n,cmp); 
			for (int j = 1; j <= n / 2; j++) {
				ans += ch[j].b1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

