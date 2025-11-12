#include <iostream>
#include <algorithm>
using namespace std;
int n,t,ans;
int cnt[5];
int vis[100003],a[100003][5];
int a1[100003];
bool cmp(int x,int y) {
	return x > y;
}
void f(int p) {
	if (p > n) {
		int s = 0;
		for (int i = 1; i <= n; i++) {
			s += a[i][vis[i]];
		}
		ans = max(ans,s);
	}
	if (cnt[1] < n / 2) {
		cnt[1]++;
		vis[p] = 1;
		f(p + 1);
		cnt[1]--;
	}
	if (cnt[2] < n / 2) {
		cnt[2]++;
		vis[p] = 2;
		f(p + 1);
		cnt[2]--;
	}
	if (cnt[3] < n / 2) {
		cnt[3]++;
		vis[p] = 3;
		f(p + 1);
		cnt[3]--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t; 
	while (t--) {
		cin >> n;
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			a1[i] = a[i][1];
			if (a[i][2] != 0 || a[i][3] != 0)    flag = false;
		}
		if (flag) {
			sort(a1 + 1,a1 + n + 1,cmp);
			ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				ans += a1[i];
			}
			cout << ans << "\n";
			continue;
		}
		ans = 0;
		cnt[1] = 0;
		cnt[2] = 0;
		cnt[3] = 0;
		f(1);
		cout << ans << "\n";
	}
	return 0;
}
