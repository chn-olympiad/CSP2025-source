#include <bits/stdc++.h>

using namespace std;
long long n,k,a[500005],xorsum[500005],l,ans,hzxorsum[500005],z[1005][1005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=1000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				long long xorsum=0;
				for(int k=i;k<=j;k++)
				{
					xorsum=(xorsum xor a[k]);
				}
				if(xorsum==k){z[i][j]=1;}
			}
		}
		long long newbegin=0;
		for(int i=1;i<=n;i++)
		{
			if(i<newbegin){continue;}
			for(int j=i;j<=n;j++)
			{
				if(z[i][j]==1){newbegin=j+1;ans++;break;}
			}
		}
		cout<<ans;
		return 0;
	}
	xorsum[0]=0,xorsum[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		xorsum[i]=(xorsum[i-1] xor a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if((xorsum[i] xor xorsum[l])==k||(xorsum[i] xor xorsum[l])==0&&xorsum[l]==k){ans++;l=i;}
	}
	cout<<ans;
	return 0;
}

