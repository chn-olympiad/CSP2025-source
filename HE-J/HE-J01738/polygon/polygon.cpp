#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],cnt=0,sum=0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1; i<=n; i++)
	{
		int maxn=0;
		maxn=max(maxn,a[i]);
		if(2*maxn==sum)
		{
			cnt++;
		}
	}
	cout<<cnt%998244353;
	return 0;
}
