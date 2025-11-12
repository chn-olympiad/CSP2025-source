#include <bits/stdc++.h>
using namespace std;

int a[500001];

int inf=-1; 

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans=0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			bool flag=false;
			for (int k = i; k <= j; k++)
			{
				if (a[k]==-1) flag=true;
			}
			if (flag) continue;
			int now=0;
			for (int k = i; k <= j; k++)
			{
				now^=a[k];
			}
			if (now==m)
			{
				ans++;
				for (int k = i; k <= j; k++)
				{
					a[k]=-1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
//暴力大法，0~25pts 
//无能为力 
