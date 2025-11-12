#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll a[N][4],s1[N],s2[N],s3[N];
int T;
int Max(int a,int b,int c) {
	if(a>=b&&a>=c) return 1;
	if(b>=a&&b>=c) return 2;
	if(c>=a&&c>=b) return 3;
}
inline void solve() {
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(s3,0,sizeof(s3));
	ll ans=0;
	int cnt1=0,cnt2=0,cnt3=0;
	for(register int i=1;i<=n;++i) {
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		int k=Max(a[i][1],a[i][2],a[i][3]);
		ans+=a[i][k];
		if(k==1) s1[++cnt1]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
		if(k==2) s2[++cnt2]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
		if(k==3) s3[++cnt3]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
	}
	if(cnt1>n/2) {
		sort(s1+1,s1+cnt1+1);
		for(register int i=1;i<=cnt1-n/2;++i) ans-=s1[i];
	}
	if(cnt2>n/2) {
		sort(s2+1,s2+cnt2+1);
		for(register int i=1;i<=cnt2-n/2;++i) ans-=s2[i];
	}
	if(cnt3>n/2) {
		sort(s3+1,s3+cnt3+1);
		for(register int i=1;i<=cnt3-n/2;++i) ans-=s3[i];
	}
	printf("%lld\n",ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
}
