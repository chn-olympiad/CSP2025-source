#include<bits/stdc++.h>
using namespace std;
bool issjx(int a,int b,int c)
{
	if(a+b>c&&a+c>b&&b+c>a)
		return true;
	return false;
}
bool issbx(int a,int b,int c,int d)
{
	int maxx=max(max(a,b),max(c,d));
	int tot=a+b+c+d;
	if(tot>2*maxx)return true;
	else return false;
}
long long czh(int m,int n)
{
	long long jcn=1;
	long long jcm=1;
	for(int i=1;i<=n;i++)
	{
		jcn*=i;
	}
	for(int i=m-n+1;i<=m;i++)
	{
		jcm*=i;
	}
	return jcm/jcn;
}
bool iswbx(int a,int b,int c,int d,int e)
{
	int maxx=max(max(max(a,b),max(c,d)),e);
	int tot=a+b+c+d+e;
	if(tot>2*maxx)return true;
	else return false;
}
bool islbx(int a,int b,int c,int d,int e,int f)
{
	int maxx=max(max(max(a,b),max(c,d)),max(e,f));
	int tot=a+b+c+d+e;
	if(tot>2*maxx)return true;
	else return false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	int maxs=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(maxs<a[i])maxs=a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	long long maxn=0;
	if(maxs==1)
	{
		for(int i=3;i<=n;i++)
		{
			maxn=(maxn+czh(n,i))%998244353;
		} 
		cout<<maxn;
		return 0;
	}
	if(n==4)
	{
		for(int i=3;i<=n;i++)
		{
			if(i==3)
			{
				for(int j=1;j<=2;j++)
				{
					for(int k=j+1;k<=3;k++)
					{
						for(int l=k+1;l<=4;l++)
						{
							if(issjx(a[j],a[k],a[l]))maxn++;
						}
					}
				}
			}
			if(i==4)
			{
				if(issbx(a[1],a[2],a[3],a[4]))maxn++;
			}
		}
		cout<<maxn;
		return 0;
	}
	if(n==5)
	{
		for(int i=3;i<=n;i++)
		{
			if(i==3)
			{
				for(int j=1;j<=3;j++)
				{
					for(int k=j+1;k<=4;k++)
					{
						for(int l=k+1;l<=5;l++)
						{
							if(issjx(a[j],a[k],a[l]))maxn++;
						}
					}
				}
			}
			if(i==4)
			{
				for(int j=1;j<=2;j++)
				{
					for(int k=j+1;k<=3;k++)
					{
						for(int l=k+1;l<=4;l++)
						{
							for(int p=l+1;p<=5;p++)
							if(issbx(a[j],a[k],a[l],a[p]))maxn++;
						}
					}
				}
			}
			if(i==5)
			{
				if(iswbx(a[1],a[2],a[3],a[4],a[5]))maxn++;
			}
		}
		cout<<maxn;
		return 0;
	}
	if(n==6)
	{
		for(int i=3;i<=n;i++)
		{
			if(i==3)
			{
				for(int j=1;j<=4;j++)
				{
					for(int k=j+1;k<=5;k++)
					{
						for(int l=k+1;l<=6;l++)
						{
							if(issjx(a[j],a[k],a[l]))maxn++;
						}
					}
				}
			}
			if(i==4)
			{
				for(int j=1;j<=3;j++)
				{
					for(int k=j+1;k<=4;k++)
					{
						for(int l=k+1;l<=5;l++)
						{
							for(int p=l+1;p<=6;p++)
							if(issbx(a[j],a[k],a[l],a[p]))maxn++;
						}
					}
				}
			}
			if(i==5)
			{
				for(int j=1;j<=2;j++)
				{
					for(int k=j+1;k<=3;k++)
					{
						for(int l=k+1;l<=4;l++)
						{
							for(int p=l+1;p<=5;p++)
								for(int q=p+1;q<=6;q++)
								if(iswbx(a[j],a[k],a[l],a[p],a[q]))maxn++;
						}
					}
				}
			}
			if(i==6)
			{
				if(islbx(a[1],a[2],a[3],a[4],a[5],a[6]))maxn++;
			}
		}
		cout<<maxn;
		return 0;
	}
	return 0;
} 
