#include <iostream>
using namespace std;
signed main()
{
	int n,m,k;
	cin >> n >> m >> k;
	int u[m+1],v[m+1],w[m+1];
	int sum1=0,sum2=0;
	for (int i=1;i<=m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		sum1+=w[i];
	}
	int c[k+1],a[k+1][n+1];
	for (int i=1;i<=k;i++)
	{
		cin >> c[i];
		sum2+=c[i];
		for (int j=1;j<=n;j++)
		{
			cin >> a[i][j];
			sum2+=a[i][j];
		}
	}
	int cnt1,cnt2;
	if (sum1>=sum2)
	{
		cnt1=sum1;
		cnt2=sum2;
	}
	else
	{
		cnt1=sum2;
		cnt2=sum1;
	}
	cout << int(cnt2-cnt1*1.5/cnt2);
	return 0;
}
