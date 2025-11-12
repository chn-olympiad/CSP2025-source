#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
	cin>>n>>k;
	int a[n+5];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0;	
	if (k==0)
	{
        for (int i=1;i<=n;i++)
		{
			if (a[i]==0)
			{
				sum++;
			}
			else if (a[i]==1 && a[i+1]==1)
			{
				sum++;
			}
		}
		cout<<sum;
		return 0;		
	}
	if (k==1)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]==1)
			{
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	return 0;
} 
