#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int b[23],c[23],d[23];
long long n,k,ans=0;
void ejz(long long x,int y[])
{
	int i=2,j=0;
	while(i++)
	{
		if(x<=1)
		{
			y[i]=x;
			break;
		}
		y[i]=x%2;
		x/=2;
		j++;
	}
	int z[22];
	for(int an=2;an<=i;an++) z[an]=y[an];
	for(int an=1;an<=j;an++)
	{
		y[an]=z[i-an];
	}
	y[22]=j;
	return;
}
void dfs(long long x[],long long y,long long z)
{
	long long nk=y;
	if(y>n)
	{
		if(z>ans) ans=z;
		return;
	}
	while(nk<=n)
	{
		bool mn=true;
		ejz(a[y],c);
		for(long long i=y+1;i<=nk;i++)
		{
			ejz(a[i],d);
			for(int j=1;j<=min(c[22],d[22]);j++)
			{
				if(c[j]!=d[j]) c[j]=1;
				else c[j]=0;
			}
			for(int j=1;j<=max(b[22],c[22]);j++)
			{
				if(b[j]!=c[j])
				{
					mn=false;
					break;
				}
			}
			if(mn) dfs(x,nk+1,z+1);
			else dfs(x,nk+1,z);
		}
		nk++;
	}
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k<=1)
	{
		int a1=0,a0=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) a1++;
			if(a[i]==0) a0++;
		} 
		if(k==0) cout<<a0;
		if(k==1) cout<<a1;
	}
	if(k>1)
	{
		ejz(k,b);
		dfs(a,1,0);
		cout<<ans<<endl;
	}
	return 0;
}


