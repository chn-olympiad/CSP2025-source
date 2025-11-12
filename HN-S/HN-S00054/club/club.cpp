#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int t, n, m;
ll ans;
int vis[N], vis2[N];
struct node {
	int x,id;
} p[N][4], a[N], b[N];
bool cmp(node l,node r) {
	return l.x > r.x;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		memset(vis,0,sizeof vis);
		memset(vis2,0,sizeof vis2);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		ans = 0;
		cin >> n;
		m = n / 2;
		for(int i=1; i<=n; i++) {
			for(int j = 1; j<=3; j++) {
				cin>>p[i][j].x;
				p[i][j].id = j;
			}
		}
		for(int i=1; i<=n; i++) {
			sort(p[i]+1,p[i]+4,cmp);
		}
		for(int i=1; i<=n; i++) {
			a[i].x = p[i][1].x - p[i][2].x;
			a[i].id = i;
			b[i].x = p[i][2].x - p[i][3].x;
			b[i].id = i;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1; i<=n; i++) {
			int idd = a[i].id;
			int id2 = p[idd][1].id;
			if(vis[idd]) {
				continue;
			}
			if(vis2[id2] < m) {
				vis[idd] = 1;
				ans += p[idd][1].x;
				vis2[id2]++;
			}
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1; i<=n; i++) {
			int idd = b[i].id;
			int id2 = p[idd][2].id;
			if(vis[idd]) {
				continue;
			}
			if(vis2[id2] < m) {
				vis[idd] = 1;
				ans += p[idd][2].x;
				vis2[id2]++;
			}
		}
		for(int i=1; i<=n; i++) {
			if(vis[i]) {
				continue;
			}
			ans += p[i][3].x;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
