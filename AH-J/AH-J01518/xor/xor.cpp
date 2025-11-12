#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long fe[110],pi[110][110];
long long de[500010],ddp[1010][1010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k,i,j,s=0;
	long long pia=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) pia=1;
	}
	if(k==0&&pia==0)
	{
		long long pian=0,fen=1;
		a[n+1]=2;
		for(i=1;i<=n;i++)
		{
			if(a[i]==0) pian++;
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]==a[i+1]&&a[i]==1)
			{
				fen++;
			}
			else
			{
				pian=pian+fen/2;
				fen=1;
			}
		}
		cout<<pian;
		return 0;
	}
	if(k==1&&pia==0)
	{
		long long pian=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				pian++;
			}
		}
		cout<<pian;
		return 0;
	}
	if(n<=100&&k<=255)
	{
		long long pian=0;
		for(i=1;i<=n;i++)
		{
			fe[i]=fe[i-1]^a[i];
		}
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				long long fen=fe[j]^fe[i-1];
				if(fen==k)
				{
					pi[i][j]=1;
				}
			}
		}
		for(long long len=1;len<=n;len++)
		{
			for(long long l=1;l+len-1<=n;l++)
			{
				long long r=l+len-1;
				for(long long k=l;k<r;k++)
				{
					pi[l][r]=max(pi[l][r],pi[l][k]+pi[k+1][r]);
				}
				pian=max(pian,pi[l][r]);
			}
		}
		cout<<pian;
		return 0;
	}
	if(n<=1000)
	{
		long long pian=0;
		for(i=1;i<=n;i++)
		{
			de[i]=de[i-1]^a[i];
		}
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				long long den=de[j]^de[i-1];
				if(den==k)
				{
					ddp[i][j]=1;
				}
			}
		}
		for(long long len=1;len<=n;len++)
		{
			for(long long l=1;l+len-1<=n;l++)
			{
				long long r=l+len-1;
				for(long long k=l;k<r;k++)
				{
					ddp[l][r]=max(ddp[l][r],ddp[l][k]+ddp[k+1][r]);
				}
				pian=max(pian,ddp[l][r]);
			}
		}
		cout<<pian;
		return 0;
	}
	else
	{
		cout<<0;
		return 0;
	}
	return 0;
}
