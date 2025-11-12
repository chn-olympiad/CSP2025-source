#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+100;
ll n;
ll a[maxn][4], cnt[4];
struct node {
	ll val1,val2,val3,id;
}b[maxn];
bool cmp1(node a,node b) {
	return a.val1>b.val1;
}
bool cmp2(node a,node b) {
	return a.val2>b.val2;
}
bool cmp3(node a,node b) {
	return a.val3>b.val3;
}
int main() {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T; cin>>T;
	while (T--) {
		cin>>n;
		memset (b,0,sizeof(b));
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=3; j++) 
				cin>>a[i][j];
			b[i].id=i;
			b[i].val1=a[i][1]-max(a[i][2],a[i][3]);
			b[i].val2=a[i][2]-max(a[i][1],a[i][3]);
			b[i].val3=a[i][3]-max(a[i][1],a[i][2]);
		}
		ll ans=0,sum=0;
		
		sort (b+1,b+n+1,cmp1);
		sum=0;
		for (int i=n/2+1; i<=n; i++) 
			sum+=max(a[b[i].id][2], a[b[i].id][3]);
		for (int i=1; i<=n/2; i++) {
			if (b[i].val1<0)
				{ sum=-1; break; }
			sum+=a[b[i].id][1];
		}
		ans=max(ans, sum);
		
		sort (b+1,b+n+1,cmp2);
		sum=0;
		for (int i=n/2+1; i<=n; i++) 
			sum+=max(a[b[i].id][1], a[b[i].id][3]);
		for (int i=1; i<=n/2; i++) {
			if (b[i].val2<0)
				{ sum=-1; break; }
			sum+=a[b[i].id][2];
		}
		ans=max(ans, sum);
		
		sort (b+1,b+n+1,cmp3);
		sum=0;
		for (int i=n/2+1; i<=n; i++) 
			sum+=max(a[b[i].id][2], a[b[i].id][1]);
		for (int i=1; i<=n/2; i++) {
			if (b[i].val3<0)
				{ sum=-1; break; }
			sum+=a[b[i].id][3];
		}
		ans=max(ans, sum);
		
		sum=0;
		memset (cnt,0,sizeof(cnt));
		for (int i=1; i<=n; i++) {
			if (a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
				sum+=a[i][1], cnt[1]++;
			else if (a[i][2]>=a[i][1] && a[i][2]>=a[i][3])
				sum+=a[i][2], cnt[2]++;
			else if (a[i][3]>=a[i][2] && a[i][3]>=a[i][1])
				sum+=a[i][3], cnt[3]++;
			if (cnt[1]>(n/2) || cnt[2]>(n/2) || cnt[3]>(n/2))
				{ sum=-1; break; }
		}
		ans=max(ans, sum);
		
		cout<<ans<<"\n";
	}
	return 0;
}
