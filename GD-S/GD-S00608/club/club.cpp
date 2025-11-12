#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+10;
LL n,a[N][4],o[4];
LL ch(LL x)
{
	LL mx=max(max(a[x][1],a[x][2]),a[x][3]);
	if(mx==a[x][1]) return 1;
	if(mx==a[x][2]) return 2;
	if(mx==a[x][3]) return 3;
	return 0;
}
bool cmp(LL a,LL b) { return a>b; }
void solve()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
	o[1]=o[2]=o[3]=0; LL ans=0;
	for(int i=1;i<=n;i++) ans+=a[i][ch(i)],o[ch(i)]++;
	LL mx=max(max(o[1],o[2]),o[3]),d;
	if(mx==o[1]) d=1;
	if(mx==o[2]) d=2;
	if(mx==o[3]) d=3;
	vector<LL> zxz;
	for(int i=1;i<=n;i++)
	{
		if(ch(i)==d)
		{
			LL res=-1e16;
			for(int j=1;j<=3;j++)
				if(j!=ch(i)) res=max(res,a[i][j]-a[i][ch(i)]);
			zxz.push_back(res);
		}
	}
	sort(zxz.begin(),zxz.end(),cmp);
	for(int i=0;i<mx-n/2;i++) ans+=zxz[i];
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	LL T; scanf("%lld",&T); while(T--) solve();
	return 0;
}
