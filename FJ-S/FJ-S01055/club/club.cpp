#include <bits/stdc++.h>
using namespace std;
int T, n, a1[100005], a2[100005], a3[100005];
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--) {
		int sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
			sum += max(a1[i], max(a2[i], a3[i]));
		}
		cout << sum << endl;
	}
	return 0;
}
