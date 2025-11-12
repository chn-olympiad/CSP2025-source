#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	
	int n,cnt=0;
	cin >> n;
	int a[n+1]={0};
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=3;i<=n;i++)
	{
		for (int j=1;j<=n-i+1;j++)
		{
			int yixuans=1;
			int sum=a[j];
			int max_s=1145149178;
			//cout << a[j] << " ";
			for (int k=j+1;k<=n && yixuans<=i-1;k++)
			{
				yixuans++;
				sum+=a[k];
				max_s=max(max_s,a[k]);
				//cout << a[k] << " ";
			}
			//cout << endl;
			if (sum > 2*max_s)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
