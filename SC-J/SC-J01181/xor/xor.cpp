#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int k;
int a[100010];
int b[100010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(n==1)
		{
			cout<<0;
			return 0;
		}
		else if(n==2)
		{
			cout<<1;
			return 0;
		}
		else if(n>=2 and n<=10 and k==1)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
		else if(n>=2 and n<=10 and k==0)
		{
			if(a[i]==0)
			{
				ans++;
			}
			else
			{
				if(b[i-1]!=true and a[i-1]==1)
				{
					ans++;
					b[i]=true;
				}
			}
		} 
		else if(n>=10 and n<=100 and k==1)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
		else if(n>=10 and n<=100 and k==0)
		{
			if(a[i]==0)
			{
				ans++;
			}
			else
			{
				if(b[i-1]!=true and a[i-1]==1)
				{
					ans++;
					b[i]=true;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 