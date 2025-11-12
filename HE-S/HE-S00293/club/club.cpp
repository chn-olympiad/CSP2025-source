#include<bits/stdc++.h>
using namespace std;
int a[100005][5],x[100005],cnt = 0,sum = 0;
int cntn[5][100005],c[5],js[5];
int maxx(int x,int y,int z)
{
	return max(x,max(y,z));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		if(n == 2)
		{
			for(int i = 1; i <= 3; i++)
			{
				for(int j = 1; j <= 3; j++)
				{
					if(i != j)
					{
						x[++cnt] = a[1][i] + a[2][j];
						sum = max(sum,x[cnt]);
					}
					
				}
			}
			cout << sum << endl;
		}
		else if(n == 4)
		{
			for(int i = 1; i <= 3; i++)
			{
				for(int j = 1; j <= 3; j++)
				{
					for(int k = 1; k <= 3; k++)
					{
						for(int l = 1; l <= 3; l++)
						{
							if(!(i == j && i == k || i == j && i == l || i == k && i == l || j == k && j == l))
							{
								x[++cnt] = a[1][i] + a[2][j] + a[3][k] + a[4][l];
								sum = max(sum,x[cnt]);
							}
						}
					}
					
					
				}
			}
			cout << sum << endl;
		}
		else
		{
			int sum = 0;
			memset(cntn,0,sizeof(cnt));
			memset(c,0,sizeof(c));
			memset(js,0,sizeof(js));
			int minid[5],minn[5] = {0,2e9,2e9,2e9};
			for(int i = 1; i <= n; i++)
			{
				cin >> a[i][1] >> a[i][2] >> a[i][3];
				for(int j = 1; j <= 3; j++)
				{
					if(a[i][j] == maxx(a[i][1],a[i][2],a[i][3]))
					{
						sum += a[i][j];
						c[j]++;
						cntn[j][++js[j]] = a[i][j];
						if(a[i][j] < minn[j])
						{
							minn[j] = a[i][j];
							minid[j] = i;
						}
					}
					if(c[j] > n / 2)
					{
						int x = (j + 1) % 3,y = (j + 2) % 3;
						if(x == 0) x = 3;
						if(y == 0) y = 3;
						if(a[minn[j]][x] > a[minn[j]][y]) 
						{
							c[x]++;
							sum += a[minid[j]][x] - minn[j];
						}	
						else
						{
							c[y]++;
							sum += a[minid[j]][y] - minn[j];
						}
						c[j]--,cntn[j][minid[j]] = 0;
						for(int k = 1; k <= c[j]; k++)
						{
							minn[j] = 2e9;
							if(cntn[j][k] < minn[j] && cntn[j][k] != 0)
							{
								minn[j] = cntn[j][k];
								minid[j] = k;
							}
						}
					}
				}
			}
			cout << sum << endl;
		}
	}
	return 0;
}
