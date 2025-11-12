#include <bits/stdc++.h>
using namespace std;

int T,n,ans,a[100005][4],b[100005],c[100005],p,q,cnt,t[100005];
bool f[100005];
bool cmp(int x,int y) {return max(a[x][2],a[x][3]) < max(a[y][2],a[y][3]);}

int main() {
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		ans = p = q = cnt = 0;
		for (int i = 1;i <= n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		for (int i = 1;i <= n;i++) f[i] = 1;
		for (int i = 1;i <= n;i++) {
			ans += a[i][1];
			a[i][2] -= a[i][1];
			a[i][3] -= a[i][1];
		}
		for (int i = 1;i <= n;i++) t[i] = i;
		sort(t + 1,t + n + 1,cmp);
		for (int i = 1;i <= n;i++)
			if (cnt >= n / 2) break;
			else if (max(a[t[i]][2],a[t[i]][3]) <= 0) cnt++,f[t[i]] = 0;
		for (int i = 1;i <= n;i++)
			if (f[i]) {
				ans += max(a[i][2],a[i][3]);
				if (a[i][2] > a[i][3]) b[++p] = a[i][2] - max(a[i][3],0);
				else c[++q] = a[i][3] - max(a[i][2],0);
			}
		if (p > n / 2) {
			sort(b + 1,b + p + 1);
			for (int i = 1;i <= p - n / 2;i++) ans -= b[i];
		}
		if (q > n / 2) {
			sort(c + 1,c + q + 1);
			for (int i = 1;i <= q - n / 2;i++) ans -= c[i];
		}
		cout << ans << endl;
	}
	return 0;
}