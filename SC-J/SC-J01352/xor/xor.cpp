#include <bits/stdc++.h>
using namespace std;
long long n,k,x,cnt;
long long a[500005];
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
		for(int j=i;j<=n;j++)
		{
			x=0;
			for(int k=i;k<=j;k++)
			{
				x^=a[k];
			}
			if(x==k)
			{
				cnt++;
				i=j;
			}	
		}
	}
	cout<<cnt;
	return 0;
}