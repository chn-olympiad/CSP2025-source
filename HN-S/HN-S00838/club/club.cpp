#include <bits/stdc++.h>
using namespace std;
int t,cnt;
long long n,sum; 
int a[100005][5],d[5]; 
bool sfcg()
{
	for (int j = 0;j < 3;j++)
		if (d[j] >= n/2)
			return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int w = 1;w <= t;w++)
	{
		cin >> n;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < 3;j++)
			{
				cin >> a[i][j];
				//cout << a[i][j] << " ";
			}
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				if (a[i][j] >= a[i][j+1])
				{
					cnt = j;
					//d[j]++;
					//cout << cnt << " ";
					//cout << d[cnt] << endl;
					//if (sfcg())
						//sum += a[i][cnt];
				}
				else
				{
					cnt = j+1;
					//d[j+1]++;
					//cout << cnt << " ";
					//cout << d[cnt] << endl;
					//if (sfcg())
						//sum += a[i][cnt];
				}
			}
			for (int j = 0;j < 3;j++)
			{
				d[cnt]++;
				if (sfcg())
					sum += a[i][cnt];
				else
				{
					int man;
					while (man != cnt)
						man = max(d[j],d[j+1]);
					sum += a[i][man];
				}
			}
		}
		//cout << cnt;
		//for (int i = 0; i < n;i++)
		{
			
		}
		//for (int i = 0;i < t;i++)
		{
			//sum += a[i][cnt];
		}
		cout << sum << endl;
	}
	return 0;
}
