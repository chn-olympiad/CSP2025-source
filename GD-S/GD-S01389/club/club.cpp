#include<bits/stdc++.h>
using namespace std;
struct node {
	int x, y, z;
	int maxx;
} a[100005];
int cntx, cnty, cntz;
bool cmp(node i, node j) {
	return i.maxx>=j.maxx;
}
long long ans=0;
bool isx, isy, isz;
int dp[1000005]; 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int q;
	cin >> q;
	int n;
	while (q--) {
		cntx=0, cnty=0, cntz=0;
		isx=0, isy=0, isz=0;
		ans=0;
		cin >> n;
		for (int i=1;i<=n;i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].maxx=max(a[i].x, max(a[i].y, a[i].z));
			if (a[i].x!=0) isx=1;
			if (a[i].y!=0) isy=1;
			if (a[i].z!=0) isz=1;
		}
		int flag=n/2;
		sort(a+1, a+n+1, cmp);
		if (!isx&&!isy&&!isz) {
			cout << 0 << endl;
			continue;
		} else if (!isy&&!isz) {
			for (int i=1;i<=n/2;i++) {
				ans+=a[i].x;
			}
			cout << ans << endl;
			continue;
		} else if (!isx&&!isz) {
			for (int i=1;i<=n/2;i++) {
				ans+=a[i].y;
			}
			cout << ans << endl;
			continue;
		} else if (!isx&&!isy) {
			for (int i=1;i<=n/2;i++) {
				ans+=a[i].z;
			}
			cout << ans << endl;
			continue;
		}
		for (int i=1;i<=n;i++) {
			if (a[i].x==a[i].maxx&&cntx<flag) {
				cntx++;
				ans+=a[i].x;
			} else if (a[i].y==a[i].maxx&&cnty<flag) {
				cnty++;
				ans+=a[i].y;
			} else if (a[i].z==a[i].maxx&&cntz<flag) {
				cntz++;
				ans+=a[i].z;
			} else {
				if (cntx<flag&&cnty<flag) {
					if (a[i].x>a[i].y) {
						ans+=a[i].x;
						cntx++;
					} else {
						ans+=a[i].y;
						cnty++;
					}
				} else if (cntx<flag&&cntz<flag) {
					if (a[i].x>a[i].z) {
						ans+=a[i].x;
						cntx++;
					} else {
						ans+=a[i].z;
						cntz++;
					}
				} else if (cnty<flag&&cntz<flag) {
					if (a[i].y>a[i].z) {
						ans+=a[i].y;
						cnty++;
					} else {
						ans+=a[i].z;
						cntz++;
					}
				} else if (cntx<flag) {
					ans+=a[i].x;
					cntx++;
				} else if (cnty<flag) {
					ans+=a[i].y;
					cnty++;
				} else {
					ans+=a[i].z;
					cntz++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

