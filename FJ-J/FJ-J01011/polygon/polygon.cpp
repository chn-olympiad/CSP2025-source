#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5006];
	int cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int l=j+1;l<=n;l++)
				{
					if(a[i]+a[j]+a[l]>=max(max(a[i],a[j]),max(a[j],a[l]))*2)
					{
						cnt++;
					}
				}
		}
	}
	cout << cnt;
	return 0;
}
