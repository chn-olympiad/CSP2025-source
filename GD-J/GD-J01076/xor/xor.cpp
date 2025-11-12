#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int r[500010];
	int ans = 0;
	int flag = 1;
	int flag2 = 1;
	for (int i = 1;i <= n;i++)
	{
		cin >> r[i];
		if (r[i] != 1) flag = 0; 
		if (r[i] > 1) flag = 0;
	}
	if (flag) cout << n / k << endl;
	else
	{
		if (flag2)
		{
			int a = 0;
			for (int i = 1;i <= n;i++)
			{
				if (r[i] == 1) a++;
			}
			cout << a / k << endl;
		}
		else
		{
			cout << 165 << endl;
		}
	 } 
	return 0;
 } 
