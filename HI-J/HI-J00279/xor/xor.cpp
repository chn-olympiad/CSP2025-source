#include<bits/stdc++.h>
using namespace std;
int k,n,a[500005],ans;
bool b=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			int x=a[i];
			for (int q=i+1;q<=j;q++)
			{
				x=a[q]^x;
				if (a[q]==k)
				{
					b=1;
					break;
				} 
			}
			if (b)
			{
				ans++;
				i=j;
				b=0;
				break;
			}
			if (x==k)
			{
				ans++;
				i=j;
				break;
			}
			
		}
	}
	cout<<ans;
	return 0;
} 
