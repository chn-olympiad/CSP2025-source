#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	int sum[t + 1];
	for (int k = 1;k <= t;k++)
	{
		sum[k] = 0;
		int n;
		cin >> n;
		int a[n + 1][5];
		int maxn[n + 1], maxx[n + 1];
		int max1[n + 1];
		int maxsum[5];
		for (int i = 1;i <= n;i++)
		{
			a[i][1] = 0;
			a[i][2] = 0;
			a[i][3] = 0;
			maxn[i] = 0;
			maxx[i] = 0;
			max1[i] = 0;
		}
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2])
			{
				if (a[i][2] >= a[i][3])
				{
					maxn[i] = a[i][1];
					max1[i] = 1;
					maxsum[1]++;
					maxx[i] = a[i][2];
				}
				else if (a[i][3] >= a[i][1])
				{
					maxn[i] = a[i][3];
					max1[i] = 3;
					maxsum[3]++;
					maxx[i] = a[i][1];
				}
				else
				{
					maxn[i] = a[i][1];
					max1[i] = 1;
					maxsum[1]++;
					maxx[i] = a[i][3];
				}
					
			}
			else if (a[i][2] >= a[i][3])
			{
				if (a[i][3] >= a[i][1])
				{
					maxn[i] = a[i][2];
					max1[i] = 2;
					maxsum[2]++;
					maxx[i] = a[i][3];
				}
				else if (a[i][1] >= a[i][2])
				{
					maxn[i] = a[i][1];
					max1[i] = 1;
					maxsum[1]++;
					maxx[i] = a[i][2];
				}
				else
				{
					maxn[i] = a[i][2];
					max1[i] = 2;
					maxsum[2]++;
					maxx[i] = a[i][1];
				}
					
			}
			else if (a[i][3] >= a[i][1])
			{
				if (a[i][1] >= a[i][2])
				{
					maxn[i] = a[i][3];
					max1[i] = 3;
					maxsum[3]++;
					maxx[i] = a[i][1];
				}
				else if (a[i][2] >= a[i][3])
				{
					maxn[i] = a[i][2];
					max1[i] = 2;
					maxsum[2]++;
					maxx[i] = a[i][3];
				}
				else
				{
					maxn[i] = a[i][3];
					max1[i] = 3;
					maxsum[3]++;
					maxx[i] = a[i][2];
				}
			}
		}//最大值 
		for (int i = 1;i <= n;i++)
		{
			if (maxsum[1] > n / 2)
			{
				if (max1[i] == 1)
					maxsum[1]--;
			}
			if (maxsum[2] > n / 2)
			{
				if (max1[i] == 2)
					maxsum[2]--;
			}
			if (maxsum[3] > n / 2)
			{
				if (max1[i] == 3)
					maxsum[3]--;
			}
			else
				sum[k] += maxn[i];
		}//处理重复(这一块貌似没调好qwq) 
	}//t次样例 
	for (int k = 1;k <= t;k++)
		cout << sum[k] << endl;//输出t个数据 
	return 0;
}
