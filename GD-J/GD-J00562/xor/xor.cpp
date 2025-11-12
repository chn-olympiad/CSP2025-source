#include <bits/stdc++.h>
using namespace std;

long long n,de;
long long a[1000000];
long long b[1000000];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>de;
	if(de==0)
	{
		cout<<1;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int p=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			long long pop=0;
			for(int k=i;k<=j;k++)
			{
				
				if(int(pop|a[k])<=de && k!=i)
				{
					pop=int(pop|a[k]);
				}
				else if(k==i)
				{
					pop=int(a[k]);
				}
				
			}
			b[p]=pop;
			p++;
		}
		
	}
	long long maxn=-99999999;
	for(int i=1;i<=p;i++)
	{
		if(b[i]>maxn)
		{
			maxn=b[i];
		}
	}
	cout<<maxn;
	
	return 0;
}
