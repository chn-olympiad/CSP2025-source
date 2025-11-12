#include <bits/stdc++.h>
using namespace std;
long long n,a[5007],ans;
bool p[5007];
long long plg(int x)
{
	for(int i=x;i<=n-2;i++)
	{
		p[x]=1;
		int maxn=-1e9,sum=0;
		for(int j=1;j<=n;j++)
		{
			if(p[j])
			{
				if(a[j]>maxn)
				{
					maxn=a[j];
				}
				sum+=a[j];
			}
		}
		if(sum>maxn*2 && x>=3)
		{
			ans++;
		}
		ans+=plg(x+1);
		p[x]=0;
		for(int j=1;j<=n;j++)
		{
			if(p[j])
			{
				if(a[j]>maxn)
				{
					maxn=a[j];
				}
				sum+=a[j];
			}
		}
		if(sum>maxn*2 && x>=3)
		{
			ans++;
		}
		ans+=plg(x+1);
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	cout<<plg(1)%998244353;
}
