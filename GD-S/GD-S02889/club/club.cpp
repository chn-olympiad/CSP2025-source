#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+5;
long long n,a[maxn][3],c[maxn],b[maxn];
void solve()
{
	memset(c,-1,sizeof(c));
	memset(b,0,sizeof(b));
	long long ans=0,cnt[3];
	cnt[0]=cnt[1]=cnt[2]=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2]; 
		long long maxx=max(a[i][0],max(a[i][1],a[i][2]));
		for(long long j=0;j<=2;j++)
		{
			if(maxx==a[i][j])
			{
				ans+=a[i][j];
				c[i]=j;
				cnt[j]++;
				break;
			}
		}
	}
	long long t=0;
	long long tot=0;
	for(long long i=1;i<=n;i++)
	{
		if(c[i]==t)
		{
			long long maxx=0;
			for(long long j=0;j<=2;j++)
			{
				if(j==t)
				{
					continue;
				}
				maxx=max(maxx,a[i][j]);
			}
			b[++tot]=a[i][t]-maxx; 
		}
	}
	sort(b+1,b+tot+1);
	for(long long i=1;i<=cnt[t]-n/2;i++)
	{
		ans-=b[i];
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}
