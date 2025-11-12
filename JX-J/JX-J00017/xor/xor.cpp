#include<bits/stdc++.h>
using namespace std;
int n,a[100001],c[100001],dp;
string k;
bool pann(int z,int z1)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=z && a[i]<=z1)
		{
			return false;
		}
	}
	return true;
}
void z2(int x,int i)
{
	long long num=0,f[25];
	while(x!=0)
	{
		f[++num]=x%2;
		x/=2;
	}
	for(int j=1;j<=num;j++)
	{
		cc[i][j]=f[j];
	}
}
int xorx(int a,int b)
{
	if(a!=b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		h[i][i]=a[i];
	}
	if(pann(1,1) && k==1)
	{
		cout<<n;
	}
	else if(pann(1,1) && k==0)
	{
		cout<<n/2;
	}
	else if(pann(0,1))
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				h[i][j]=xorx(h[i][j-1],a[j]);
			}
		}
	}
	return 0;
}
