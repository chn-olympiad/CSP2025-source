#include <bits/stdc++.h>
using namespace std;
int a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		int maxn;
		if(a[i]>=a[i+1]&&a[i]>=a[i+2])
		{
			maxn=a[i];
		}
		else if(a[i+1]>=a[i]&&a[i+1]>=a[i])
		{
			maxn=a[i+1];
		}
		else
		{
			maxn=a[i+2];
		}
		if(maxn*2<a[i]+a[i+1]+a[i+2])
		{
			cnt++;
 		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
