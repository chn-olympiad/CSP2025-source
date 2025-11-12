#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
typedef pair<int,int> P;
int n,a[5005],sum[5005],inv[5005];
int f[5005][5005];
vector<P> q;
vector<P> c;
bool flag=true;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]!=1)flag=false;
	}
	if(flag)
	{
		ll ans=0;
		for(int i=3;i<=n;i++)
		{
			int a=1,b=1;
			for(int j=n;j>=i+1;j--)
			{
				a*=j;
			}
			for(int j=1;j<=i-1;j++)
			{
				b*=j;
			}
			ans+=a/b;
			ans%=mod;
		}
		printf("%lld",ans);
	}
	inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[i-1]*i%mod;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=3;i<=n;i++)
	{
		f[i][i]=(sum[i]>a[i]*2)?1:0;
		c.clear(); 
		c.push_back(P{sum[i],0});
		for(int j=i-1;j>=3;j--)
		{
			q.clear();
			int cnt=0;
			for(int k=1;k<i;k++)
			{
				for(int e=0;e<c.size();e++)
				{
					if(c[e].first-a[k]>a[i]*2&&!(c[e].second&(1<<(k-1))))
					{
						cnt++;
						cnt%=mod;
						q.push_back(P{c[e].first-a[k],c[e].second+(1<<(k-1))});
					}
				}
			}
			f[i][j]=cnt/inv[i-j];
			c.clear();
			for(int k=0;k<q.size();k++)
			{
				c.push_back(q[k]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			ans=(ll)(ans+f[i][j])%mod;
		}
	}
	printf("%d",ans);
	return 0;
}

