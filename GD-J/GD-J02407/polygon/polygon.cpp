#include <bits/stdc++.h>
using namespace std;

long long n,a[5005],ans,sum,maxx;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-3;i++)
	{
		sum=0;
		maxx=0;
		for(int j=i;j<=n;j++)
		{
			sum+=a[i];
			maxx=max(a[i],maxx);
			if(j-i+1>=3&&sum>maxx*2)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
