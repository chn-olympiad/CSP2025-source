#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt = 0;
	cin >> n >> k;
	vector<int> p(n+1);
	vector<int> q(n+1);
	vector<bool> flag(n+1,true);
	for (int i = 1;i <= n;i++)
	{
		cin >> p[i];
	}
	q[1] = p[1];
	for (int i = 2;i <= n;i++)
	{
		q[i] = p[i] ^ q[i-1];
	}
	if (q[1] == k)
	{
		cnt++;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j < i;j++)
		{
			int a = q[i] ^ q[j],num = 0;
			for (int t = j+1;t <= i;t++)
			{
				if (!flag[t])
				{
					num++;
					break;
				}
			}
			if (a == k && num == 0)
			{
				cnt++;
				for (int t = j+1;t <= i;t++)
				{
					flag[t] = false;
				}
			}
		}
	}
	cout << cnt;
	return 0;
} 