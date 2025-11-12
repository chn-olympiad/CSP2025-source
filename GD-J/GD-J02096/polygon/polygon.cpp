#include<bits/stdc++.h>
using namespace std;
int a[5010],n,b[25000010],c[25000010],ans,maxx,maxx1,mod=998244353,w[10000],cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[a[1]+a[2]]++,maxx=a[1]+a[2];
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=maxx;j++)
		{
			if(b[j])
			{
				if(j>a[i])
				{
					ans=(b[j]+ans)%mod;
				}
				c[j+a[i]]=(b[j]+b[j+a[i]])%mod;
				w[++cnt]=j+a[i];
				maxx1=max(maxx1,max(maxx,j+a[i]));
			}
		}
		maxx=max(maxx,maxx1);
		for(int j=1;j<i;j++)
		{
			b[a[i]+a[j]]++;
			maxx=max(maxx,a[i]+a[j]);
		}
		for(int j=1;j<=cnt;j++)
		{
			b[w[j]]=(c[w[j]]+b[w[j]])%mod;
		}
		cnt=0;
	}
	cout<<ans<<endl;
	return 0;
}
