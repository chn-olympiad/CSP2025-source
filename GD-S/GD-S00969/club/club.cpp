#include <bits/stdc++.h>
#define ll long long
#define maxn 100010
using namespace std;

ll a[maxn][5],cnt[5];
struct node {
	ll mx,d;
} b[maxn];

bool cmp(node x,node y) {
	return x.d<y.d;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll t=0,n;
	cin>>t;
	while (t--) {
		ll ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if (a[i][1]>=max(a[i][2],a[i][3])) {
				b[i].mx=1;
				b[i].d=a[i][1]-max(a[i][2],a[i][3]);
			}
			if (a[i][2]>=max(a[i][1],a[i][3])) {
				b[i].mx=2;
				b[i].d=a[i][2]-max(a[i][1],a[i][3]);
			}
			if (a[i][3]>=max(a[i][1],a[i][2])) {
				b[i].mx=3;
				b[i].d=a[i][3]-max(a[i][1],a[i][2]);
			}
			cnt[b[i].mx]++;
			ans+=a[i][b[i].mx];
		}
		ll mxh=0;
		for (int i=1;i<=3;i++) if (cnt[i]>n/2) mxh=i;
		if (mxh!=0) {
			sort(b+1,b+1+n,cmp);
			for (int i=1;i<=n;i++) {
				if (b[i].mx==mxh) {
					ans-=b[i].d;
					cnt[mxh]--;
				}
				if (cnt[mxh]<=n/2) break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
