#include<bits/stdc++.h>
#define fre(x) \
	freopen(x".in","r",stdin); \
	freopen(x".out","w",stdout)
#define ll long long
#define il inline
using namespace std;

const int MAXN=5e5+7;
const int MAXM=1e6+1e5+7;
const int MAXK=1e3+7;

int n,m,g[MAXM],a[MAXN],p[MAXN];
int maxx,dp[MAXN],maxn[MAXN],ans;

void solve()
{
	for(int i=1;i<=(1<<20)+1;i++)
		g[i]=-1;
	g[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(g[m^p[i]]!=-1)
			maxn[i]=max(maxn[i-1],maxn[g[m^p[i]]]+1);
		else
			maxn[i]=maxn[i-1];
		g[p[i]]=i;
	}
	printf("%d",maxn[n]);
}

int main()
{
	fre("xor");
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
//		maxx=max(maxx,a[i]);
		p[i]=p[i-1]^a[i];
	}
//	maxx<<=1;
	solve();
//	if(n<=1000)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			int sum=0;
//			for(int j=i;j>=1;j--)
//			{
//				sum^=a[j];
//				if(sum==m)
//				{
//					dp[i]=maxn[j-1]+1;
//					break;
//				}
//			}
//			maxn[i]=max(dp[i],maxn[i-1]);
////			cout<<maxn[i]<<endl;
//		}
//		printf("%d",maxn[n]);
//	}
//	else
//	{
//		for(int i=1;i<=n;i++)
//		{
//			if(g[m^a[i]])
//				maxn[i]=max(maxn[i-1],maxn[g[m^a[i]]-1]+1);
//			else
//				maxn[i]=max(maxn[i-1],1);
//			for(int j=0;j<=maxx;j++)
//				f[j]=0;
//			for(int j=0;j<=maxx;j++)
//				f[j]=g[a[i]^j];
//			f[a[i]]=i;
//			for(int j=0;j<=maxx;j++)
//				g[j]=f[j];
//		}
//		printf("%d",maxn[n]);
//	}
	return 0;
}
