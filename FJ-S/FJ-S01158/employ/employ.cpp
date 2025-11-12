#include <iostream>
#define int long long
using namespace std;
int n,m,cnt=0;
signed main()
{
	cin >> n >> m;
	string s;
	cin >> s;
	int c[n+1];
	for (int i=1;i<=n;i++)
	{
		cin >> c[i];
	}
	for (int j=0;j<=m;j++)
	{
		int sum=0,x=1;
		while (sum<=m && x<=998244353)
		{
			for (int i=1;i<=s.size();i++)
			{
				if (s[i]=='1' && c[i]-j>=0)
				{
					sum++;
				}
				else
				{
					j++;
				}
			}
		}
		cnt++;
		cnt%=998244353;
	}
	cout << cnt;
	return 0;
}
