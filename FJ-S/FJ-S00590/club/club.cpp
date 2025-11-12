#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 100006
using namespace std;
int T,n,ans,a[N][4],lef[N];
vector<int> p[4];
inline bool cmp(const int &x,const int &y){return lef[x]<lef[y];}
void solve()
{
	scanf("%lld",&n),ans=0;
	for(int i=0;i<3;i++)p[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)scanf("%lld",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		int maxpos=0;
		for(int j=1;j<3;j++)
			if(a[i][j]>a[i][maxpos])maxpos=j;
		ans+=a[i][maxpos],p[maxpos].push_back(i);
		int mx=0;
		for(int j=0;j<3;j++)if(j!=maxpos)mx=max(mx,a[i][j]);
		lef[i]=a[i][maxpos]-mx;
	}
	for(int i=0;i<3;i++)if(p[i].size()>n/2)
	{
		sort(p[i].begin(),p[i].end(),cmp);
		int d=p[i].size()-n/2;
		for(int j=0;j<d;j++)ans-=lef[p[i][j]];
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
