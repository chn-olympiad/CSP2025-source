#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],d[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		d[i] = d[i - 1]^a[i];
	}
	int end = 0,count = 0;
	for (int i = 1;i <= n;i ++)
	{
		for (int j = end;j < i;j ++)
		{
			int p = d[i]^d[j];
			if (p == k)
			{
				count++;
				end = i;
				break;
			}
		}
	}
	cout <<count;
	return 0;
}

