#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt;
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
		for(int j=i+1;j<=n;j++)
		{
			if((a[i]^a[j])==k||a[i]==k)
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
