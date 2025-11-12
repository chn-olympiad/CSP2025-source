#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],zj[5005],num,ma,sum,ans;
const long long h=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=(1<<n);i++)
	{
		num=0;
		ma=0;
		sum=0;
		for(long long j=0;j<=n;j++)
		{
			if(i&(1<<j))
			{
				num++;
				zj[num]=a[j];
				sum+=a[j];
				ma=max(ma,a[j]);
			}
		}
		if(num>=3&&sum>(ma*2))
			{
				ans++;
				ans%=h;
		}
	}
	cout<<ans;
	return 0;
}
