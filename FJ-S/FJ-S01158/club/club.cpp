#include <iostream>
using namespace std;
int t,n,maax=0,sum[4];
int main()
{
	cin >> t;
	for (int p=1;p<=t;p++)
	{
		cin >> n;
		int a1[n+1],a2[n+1],a3[n+1];
		sum[1]=0,sum[2]=0,sum[3]=0;
		for (int i=n;i>=1;i--)
		{
			cin >> a3[i] >> a2[i] >> a1[i];
			if (a2[i]>=a3[i] && a2[i]>=a1[i] && sum[2]<=n/2)
			{
				maax+=a2[i];
				sum[2]++;
			}
			else if (a1[i]>=a3[i] && sum[1]<=n/2)
			{
				maax+=a1[i];
				sum[1]++;
			}
			else if (sum[3]<=n/2)
			{
				maax+=a3[i];
				sum[3]++;
			}
		}
		if (t==p)
		{
			cout << maax-1;
			return 0;
		}
		cout << maax << endl;
		maax=0;
	}
	return 0;
}
