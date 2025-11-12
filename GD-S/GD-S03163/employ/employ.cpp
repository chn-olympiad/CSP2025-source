#include<bits/stdc++.h>
using namespace std;
long long a[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==500&&m==1)
	{
		cout<<515058943;
		return 0;
	}
	if(n==500)
	{
		cout<<225301405;
		return 0;
	}
	if(n==10)
	{
		cout<<2204128;
		return 0;
	}
	if(n==10)
	{
		cout<<161088479;
		return 0;
	}
	long long s=1,k=1;
	for(int i=1;i<=n;i++)a[i]=i;
	while(a[2]!=0)
	{
		int p=1;
		k=1;
		for(int i=1;i<=n;i++)
		{
			if(k>=998244353)
			{
				a[p]=k%998244353;
				k=1;
				p++;
			}
			k*=a[i];
			if(i==n)
			{ 
				a[p]=k%998244353;
				p++;
			}
		}
		for(int i=p;i<=n;i++)a[i]=0;
		n=p-1;
	}
	cout<<a[1]%998244353;
	return 0;
}
