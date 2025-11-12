#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std; bool MEM;
using ll=long long; using ld=long double;
using pii=pair<int,int>; using pll=pair<ll,ll>;
const int I=1e9;
const ll J=1e18,N=1e5+7;
ll n,a[N][3],ans;
vector<ll> b[3];
void mian() {
	scanf("%lld",&n),ans=0;
	b[0].clear(),b[1].clear(),b[2].clear();
	for (ll i=1;i<=n;i++) {
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		ll p=max_element(a[i],a[i]+3)-a[i],res=J; ans+=a[i][p];
		for (ll j=0;j<3;j++) if (j!=p) res=min(res,a[i][p]-a[i][j]);
		b[p].pb(res);
	}
	ll mx=-1,p=0;
	for (ll i=0;i<3;i++) if ((ll)b[i].size()>mx) mx=b[i].size(),p=i;
	if (mx>n/2) {
		sort(b[p].begin(),b[p].end());
		for (ll i=0;i<mx-n/2;i++) ans-=b[p][i];
	}
	cout<<ans<<"\n";
}
bool ORY; int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	while (1)
	int t; for (scanf("%d",&t);t--;)
	mian();
	cerr<<"\n"<<abs(&MEM-&ORY)/1048576<<"MB";
	return 0;
}
/*
把 n 个人分配到三个部门中，要求没有部门的人数 >n/2，求满意度最大值
先贪心分配。如果最优方案已经合法就不管了
否则对超的那一个进行调整。强制选出若干个分到别的部门去 
拿影响最小的几个即可。 
*/
