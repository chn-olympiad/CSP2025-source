#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	for(int k = 1;k <= t;k++)
	{
		int n;
		cin >> n;
		int a[n],b[n],c[n];
		int p[n][3];
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++) p[i][j] = j;
		}
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if(a[i] > b[i] && b[i] > c[i])
			{
				p[i][1] = 1;
				p[i][2] = 2; 
				p[i][3] = 3;
			}
			if(a[i] > c[i] && c[i] > b[i])
			{
				p[i][1] = 1;
				p[i][3] = 2;
				p[i][2] = 3;
			}
			if(b[i] > c[i] && c[i] > a[i])
			{
				p[i][2] = 1;
				p[i][3] = 2;
				p[i][1] = 3;
			}
			if(b[i] > a[i] && a[i] > c[i])
			{
				p[i][2] = 1;
				p[i][1] = 2;
				p[i][3] = 3;
			}
			if(c[i] > a[i] && a[i] > b[i])
			{
				p[i][3] = 1;
				p[i][1] = 2;
				p[i][2] = 3;
			}
			if(c[i] > b[i] && b[i] > a[i])
			{
				p[i][3] = 1;
				p[i][2] = 2;
				p[i][1] = 3;
			}
		}	
		int h[n];
		for(int i = 1;i <= n;i++)
		{
			if(p[i][1] == 1 && p[i][2] == 2) h[i] = a[i] - b[i];
			if(p[i][1] == 1 && p[i][3] == 2) h[i] = a[i] - c[i];
			if(p[i][2] == 1 && p[i][1] == 2) h[i] = b[i] - a[i];
			if(p[i][2] == 1 && p[i][3] == 2) h[i] = b[i] - c[i];
			if(p[i][3] == 1 && p[i][1] == 2) h[i] = c[i] - a[i];
			if(p[i][3] == 1 && p[i][2] == 2) h[i] = c[i] - b[i];
		}
		sort(h + 1,h + 1 + n);
		int sum[3] = {0};
		int num = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				if(p[i][j] == 1)
				{
					sum[j]++;
					if(j == 1)
					{
						num += a[i];
					}
					if(j == 2)
					{
						num += b[i];
					}
					if(j == 3)
					{
						num += c[i];
					}
				}
			}
		}
		for(int i = 1;i <= 3;i++)
		{
			if(sum[i] > n / 2)
			{
				int q = sum[i] - n / 2;
				for(int j = 0;j < q;j++)
				{
					num -= h[q];
				}
				cout << num << endl;
				break;
			}
			else if(sum[i] < n / 2 && i == 3) cout << num << endl;
		}
	}
	return 0;
}

