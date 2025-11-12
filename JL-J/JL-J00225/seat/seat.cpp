#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int main()
{
	freopen("seat.in","r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int a[N], b[N][N], c[N], cnt = 0;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	int t = a[1];
	for(int i = 1; i <= n * m; i++)
	{
		int maxN = a[i];
		for(int j = 1; j <= n * m; j++)
		{
			if(maxN < a[j])	
			{
				maxN = a[j];
				cnt = j;
			}
		}
		c[i] = maxN;
		a[cnt] = 0;
	}
	cnt = 1;
	for(int j = 1; j <= m; j++)
	{
		if(j % 2 == 1)
		{
			for(int i = 1; i <= n; i++)
			{
				b[i][j] = c[cnt];
				cnt++;
			}
		}
		else if(j % 2 == 0)
		{
			for(int i = n + 1; i > 0; i--){
				b[i][j] = c[cnt];
				cnt++;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			if(t == b[i][j])
		cout << j << " " << i;
	}
	return 0;
}
