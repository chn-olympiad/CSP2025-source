#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
long long pd(int l,int r)
{
	long long s=0;
	int maxa=0;
	for(int i=l;i<=r;i++)
	{
		s+=a[i];
		maxa=max(maxa,a[i]);
	}
	if(2*maxa<s)
	{
		return s%998244353;
	}
	else if(2*maxa>=s)
	{
		return -1;
	}
}
long long zuida=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3)
	{
		long long s1=0;
		for(int i=1;i<=n;i++)
		{
			s1+=a[i];
		}
		cout<<s1;
		return 0;
	}
	else if(n>3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=n-i;j+=i)
			{
				if(pd(i,j)!=-1)
				{
					zuida=max(pd(i,j),zuida);
				}
			}
		}
		cout<<zuida;
	}
	return 0; 
} 
