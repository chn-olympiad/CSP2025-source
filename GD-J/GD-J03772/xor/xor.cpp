#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		int num[100000]={ };
		bool b=false;
		int j=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==0) 
			{
				num[j]=1;
			}
			else if(a[i]==a[i-1]&&b==true) 
			{
				num[j]++;
				
			}
			else if(a[i]==a[i-1]&&b==false)
			{
				num[j]+=2;
			}
			else 
			{
				b=false;
				j++;
			}
		}
		int maxn=0;
		for(int i=1;i<=100000;j++)
		{
			maxn=max(maxn,num[i]);
		}
		cout<<maxn;
	}
	else if(k==1)
	{
		int num[100000]={ };
		bool b=false;
		int j=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]%2!=a[i-1]%2&&b==true) 
			{
				num[j]++;
				
			}
			else if(a[i]%2!=a[i-1]%2&&b==false)
			{
				num[j]+=2;
			}
			else 
			{
				b=false;
				j++;
			}
		}
		int maxn=0;
		for(int i=1;i<=100000;j++)
		{
			maxn=max(maxn,num[i]);
		}
		cout<<maxn;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
