#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long a[maxn];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				if(a[i]^a[j]==0)
//				{
//					cnt++;
//				}
//			}
//		}
//		cout<<cnt;
//		return 0;
		cout<<1;
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]%10!=a[j]%10&&a[i]/10==a[j]/10)
				{
					cnt++;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
