#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long ans;
long long quan(int l,int r)
{
	long long q=a[l]; 
	for (int i=l+1;i<=r;i++)
	{
		q^=a[i];
	}
	return q;
}
int main()
{
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n;
	long long k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			if (quan(i,j)==k)
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
