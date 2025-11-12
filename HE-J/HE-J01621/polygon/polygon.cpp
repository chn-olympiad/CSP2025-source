#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long a[505],jc[5005],num;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool b1=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			b1=0;
		}
	}
	jc[1]=1;
	for(int i=2;i<=500;i++)
	{
		jc[i]=(jc[i-1]*i)%MOD;
	}
	sort(a+1,a+n+1);
	if(!b1)
	{
		long long naxn=0;
		naxn+=a[1];
		naxn+=a[2];
		for(int i=3;i<=n;i++)
		{
			naxn+=a[i];
			if(naxn<a[i]*2)
			{
				continue;
			}
			else if(naxn==a[i]*2)
			{
				num++;
				continue;
			}
			long long js;
			for(int j=1;j<=i/2;j++)
			{
				js=j;
				for(int k=i-1;k>=1;k--)
				{
					js++;
					if(k==j)
					{
						break;
					}
					else if(a[j]+a[k]<a[i])
					{
						break;
					}
					num++;
					long long zhs=0,t;
					for(int ii=1;ii<=i-js;ii++)
					{
						t=jc[i-js]%MOD/((jc[ii]*jc[i-js-ii])%MOD);
						zhs+=t;
						zhs%=MOD;
					}
					num+=zhs;
					num%=MOD;
				}
			}
		}
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			long long zhs=(jc[n]%MOD/(jc[i]*jc[n-i])%MOD)%MOD;
			num+=zhs;
			num%MOD;
		}
	}
	cout<<num;
	return 0;
}



