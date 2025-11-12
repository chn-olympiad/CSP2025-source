#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6+10; 
int n,m,k,pre[MAXN],ans;
int zx(int x) {
	if (x != pre[x]) pre[x] = zx(pre[x]);
	return pre[x];
}
struct node {
	int x,y,val;
}a[MAXN];
bool cmp(node u,node v) {
	return u.val < v.val;
}
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
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		a[i].x = read();
		a[i].y = read();
		a[i].val = read();
	}
	if (k == 0) {
		for (int i = 1; i <= n; i ++) pre[i] = i;
		int cnt = 0;
		sort (a+1,a+m+1,cmp);
		for (int i = 1; i <= m; i ++) {
			if (cnt == n-1) break;
			int f1 = zx(a[i].x);
			int f2 = zx(a[i].y);
			if (f1 != f2) {
				cnt ++;
				ans += a[i].val;
				pre[f1] = f2;
			}
		}
		cout << ans;
		exit(0);
	}
	for (int i = 1; i <= k; i ++) {
		int pp;
		cin >> pp;
		int b[10005];
		for (int i = 1; i <= n; i ++)
		cin >> b[i];
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j < i; j ++) {
				a[++m].x = i,a[m].y = j,a[m].val = b[i]+b[j];
			}
		}
	}
	int cnt = 0;
	sort (a+1,a+m+1,cmp);
	for (int i = 1; i <= n; i ++) pre[i] = i;
	for (int i = 1; i <= m; i ++) {
		if (cnt == n-1) break;
		int f1 = zx(a[i].x);
		int f2 = zx(a[i].y);
		if (f1 != f2) {
			cnt ++;
			ans += a[i].val;
			pre[f1] = f2;
		}
	}
	cout << ans;
	return 0;
}

