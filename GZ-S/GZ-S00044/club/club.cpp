/*
	刘凌睿
	GZ-S00044
	贵阳市南明区华麟学校 
*/
#include<bits/stdc++.h>
using namespace std;
long long a[300005][10],t,n,b[100005];
bool pd()
{
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=3;j++)
		{
			if(a[i][j]==0) flag=1;
			else
			{
				return false;
			} 
		}
	}
	if(flag==1) return true;
}
bool pdz()
{
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][1]==0&&a[i][3]==0) flag=1;
		else
		{
			return false;
		} 
	}
	if(flag==1) return true;
}
bool pdy()
{
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			if(a[i][j]==0) flag=1;
			else
			{
				return false;
			} 
		}
	}
	if(flag==1) return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		if(pd()==1)
		{
			long long cnt=0,s=0;
			for(int i=1;i<=n;i++)
			{
				b[++cnt]=a[i][1];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--)
			{
				s+=b[i];
			}
			cout<<s<<endl;
			continue;
		}
		else if(pdy()==1)
		{
			long long cnt=0,s=0;
			for(int i=1;i<=n;i++)
			{
				b[++cnt]=a[i][3];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--)
			{
				s+=b[i];
			}
			cout<<s<<endl;
			continue;
		}
		else if(pdz()==1)
		{
			long long cnt=0,s=0;
			for(int i=1;i<=n;i++)
			{
				b[++cnt]=a[i][2];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--)
			{
				s+=b[i];
			}
			cout<<s<<endl;
			continue;
		}
		if(n==2)
		{
			long long maxn1=0,maxn2=0;
			for(int i=1;i<=3;i++)
			{
				maxn1=max(maxn1,a[1][i]);
				maxn2=max(maxn2,a[2][i]);
			}
			cout<<maxn1+maxn2<<endl;
			continue;
		}
		long long maxn=0,s=0;
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=3;i++)
			{
				maxn=max(maxn,a[j][i]);
			}
			s+=maxn;
			maxn=0;
		}
		cout<<s<<endl;
	}
	return 0;
}
