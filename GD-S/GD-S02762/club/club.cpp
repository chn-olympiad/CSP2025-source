#include <bits/stdc++.h>
using namespace std;

int T;
long long ans;
const int MAXN = 1e5+10;
int read() {
	int ans = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {if (c == '-') f = -1;c = getchar();}
	while (c >= '0' && c <= '9') {
		ans = ans*10+c-'0';
		c = getchar();
	}
	return ans*f;
}
struct node {
	int val,id;
}bbb[MAXN],ccc[MAXN],bbcc[MAXN];
bool cmp1(node u,node v) {
	return u.val > v.val; 
}
bool cmp2(node u,node v) {
	return u.val < v.val; 
}
signed main() {
freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T --) {
		int n,a[MAXN][5],b[MAXN],c[MAXN],d[MAXN],bc[MAXN];
		ans = 0;
		cin >> n;
		int mid = n/2;
		int a1 = n, a2 = 0, a3 = 0;
		for (int i = 1; i <= n; i ++) {
			a[i][1] = read();
			a[i][2] = read();
			a[i][3] = read();
			ans = ans + a[i][1];
			b[i] = a[i][2]-a[i][1];
			c[i] = a[i][3]-a[i][1];
			bc[i] = a[i][2]-a[i][3];
			d[i] = 1;
		}
		for (int i = 1; i <= n; i ++) {
			if (b[i] < 0) {
				if (c[i] >= 0) ans += c[i], d[i] = 3, a3 ++, a1 --;
			}
			else if (b[i] > 0) {
				if (b[i] < c[i]) ans += c[i], d[i] = 3, a3 ++,a1 --;
				else if (b[i] == c[i]) {
					if (a2 > a3) ans += c[i], d[i] = 3, a3 ++,a1 --;
					else ans += b[i], d[i] = 2, a2 ++,a1 --;
				}
				else ans += b[i], d[i] = 2, a2 ++,a1 --;
			}
			else ans += b[i], d[i] = 2, a2 ++,a1 --;
		}
		for (int i = 1; i <= n; i ++) bbb[i].val = b[i],bbb[i].id = i,ccc[i].val = c[i],ccc[i].id = i,bbcc[i].val = bc[i],bbcc[i].id = i;
		if (a1 <= mid && a2 <= mid && a3 <= mid) {
			cout << ans << endl;
			continue;
		}
		else if (a1 > mid) {
			sort (bbb + 1,bbb + n + 1,cmp1);
			sort (ccc + 1,ccc + n + 1,cmp1);
			int bb = 1,cc = 1;
			while (a1 > mid) {
				for (int i = 1; i <= n+1; i ++) {
					if (bbb[i].val != -INT_MAX && d[bbb[i].id] != 2) {
						bb = i;
						break;
					}
				}
				for (int i = 1; i <= n+1; i ++) {
					if (ccc[i].val != -INT_MAX && d[ccc[i].id] != 3) {
						cc = i;
						break;
					}
				}
				if (bbb[bb].val > ccc[cc].val && bb<=n && d[bbcc[bb].id] == 1) d[bbb[bb].id] = 2, ans += bbb[bb].val, bbb[bb].val = -INT_MAX;
				else d[ccc[cc].id] = 3, ans += ccc[cc].val, ccc[cc].val = -INT_MAX;
				a1 --;
			}
			cout << ans << endl;
		}
		else if (a2 > mid) {
			sort (bbb + 1,bbb + n + 1,cmp2);
			sort (bbcc + 1,bbcc + n + 1,cmp2);
			int bb = 1,cc = 1;
			for (int i = 1; i <= n; i ++) bbb[i].val = -bbb[i].val, bbcc[i].val = -bbcc[i].val;
			while (a2 > mid) {
				for (int i = 1; i <= n+1; i ++) {
					if (bbb[i].val != -INT_MAX && d[bbb[i].id] != 1) {
						bb = i;
						break;
					}
				}
				for (int i = 1 ; i <= n+1; i ++) {
					if (bbcc[i].val != -INT_MAX && d[bbcc[i].id] != 3) {
						cc = i;
						break;
					}
				}
				if (bbb[bb].val > bbcc[cc].val && bb<=n && d[bbcc[bb].id] == 2) d[bbb[bb].id] = 1, ans += bbb[bb].val, bbb[bb].val = -INT_MAX;
				else d[bbcc[cc].id] = 3, ans += bbcc[cc].val, bbcc[cc].val = -INT_MAX;
				a2 --;
			}
			cout << ans << endl;
		}
		else {
			sort (bbcc + 1,bbcc + n + 1,cmp1);
			sort (ccc + 1,ccc + n + 1, cmp2);
			int bb = 1,cc = 1;
			for (int i = 1; i <= n; i ++) ccc[i].val = -ccc[i].val;
			while (a3 > mid) {
				for (int i = 1; i <= n+1; i ++) {
					if (bbcc[i].val != -INT_MAX && d[bbcc[i].id] != 2) {
						bb = i;
						break;
					}
				}
				for (int i = 1; i <= n+1; i ++) {
					if (ccc[i].val != -INT_MAX && d[ccc[i].id] != 1) {
						cc = i;
						break;
					}
				}
				if (bbcc[bb].val > ccc[cc].val && bb <= n && d[bbcc[bb].id] == 3) d[bbcc[bb].id] = 2, ans += bbcc[bb].val, bbcc[bb].val = -INT_MAX;
				else d[ccc[cc].id] = 1, ans += ccc[cc].val, ccc[cc].val = -INT_MAX;
				a3 --;
			}
			cout << ans << endl;
		}
	}
	return 0;
} 
