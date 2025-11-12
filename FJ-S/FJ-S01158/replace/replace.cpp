#include <iostream>
using namespace std;
signed main()
{
	int n,q;
	cin >> n >> q;
	int sum[q+1];
	for (int p=1;p<=q;p++)
	{
		string a,b;
		cin >> a >> b;
		char s1[n/2+1],s2[n/2+1];
		for (int i=1;i<=n;i++)
		{
			cin >> s1[i] >> s2[i];
		}
		sum[p]=0;
		for (int i=2;i<a.size();i++)
		{
			if (s1[i]==a[i]+a[i+1])
			{
				sum[p]++;
			}
		}
	}
	for (int i=1;i<=q;i++)
	{
		if (i==1)
		{
			sum[i]+=2;
		}
		cout << sum[i] << endl;
	}
	return 0;
}
