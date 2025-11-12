#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mp[10010],n,a[10010],sum,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=0;j--)
		{
			if(i>=3 and j>a[i])
			{
				ans+=mp[j];
				ans%=998244353;
			}
			if(j+a[i]>5001)
			{
				mp[5001]+=mp[j];
				mp[5001]%=998244353;
			}
			else
			{
				mp[j+a[i]]+=mp[j];
				mp[j+a[i]]%=998244353;
			}
		}
		if(sum<5001)
		{
			sum+=a[i];
			if(sum>=5001)sum=5001;
		}
	}
	cout<<ans;
	return 0;
}
