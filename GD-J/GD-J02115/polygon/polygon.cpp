#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,b[5005],l,maxx,ans2,z=0;
int main()
{
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","s",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	for(int i=3;i<=n;i++)
	{
		ans=b[i];
		if(ans>a[i]*2)maxx++;
		else continue;
		for(int j=1;j<i;j++)
		{
			maxx=maxx%998244353;
			if(ans-a[j]>a[i]*2)
			{
				maxx++;
				ans2=ans;
				ans-=a[j];
				l=j;
				z++;
			}
			else if(z>0)
			{
				ans+=a[j];
				j--;
				z--;
			}
		}
	}
	cout<<maxx;
	return 0;
}

