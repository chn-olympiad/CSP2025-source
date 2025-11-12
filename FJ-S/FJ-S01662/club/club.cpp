#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000000 + 10;
int t;
int n;
struct node {
	int s;
	int i;
};
bool cmp(node a,node b) {
	return a.s > b.s;
}
node a[4][N];
bool vis[N];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
			cin >> a[i][1].s >> a[i][2].s >> a[i][3].s;
			a[i][1].i = 1,a[i][2].i = 2,a[i][3].i = 3;
			if (a[i][1].s < a[i][2].s) swap(a[i][1].s, a[i][2].s);
			if (a[i][2].s < a[i][3].s) swap(a[i][2].s, a[i][3].s);
			if (a[i][1].s < a[i][2].s) swap(a[i][1].s, a[i][2].s);
		}
		int a_len[4] = {0},q = n / 2;
		int ans = 0;
		sort(a[1] + 1,a[1] + n + 1,cmp);
		for (int i = 1;i <= n;i++){
			if (vis[i]) continue;
			if (a_len[a[i][1].i] <= q) ans += a[i][1].s, a_len[a[i][1].i]++, vis[i] = true;
		}
		sort(a[2] + 1,a[2] + n + 1,cmp);
		for (int i = 1;i <= n;i++){
			if (vis[i]) continue;
			if (a_len[a[i][2].i] <= q) ans += a[i][2].s, a_len[a[i][2].i]++, vis[i] = true;
		}
		sort(a[3] + 1,a[3] + n + 1,cmp);
		for (int i = 1;i <= n;i++){
			if (vis[i]) continue;
			if (a_len[a[i][3].i] <= q) ans += a[i][3].s, a_len[a[i][3].i]++, vis[i] = true;
		}
		cout<<ans<<endl;
	}
	return 0;
}