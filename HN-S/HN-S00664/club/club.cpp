#include <bits/stdc++.h>
using namespace std;

int t;
int b[110][110][110];

inline x_max(int a, int b, int c)
{
	return max(a, max(b, c));
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n, a[210][3];
		cin >> n;
		memset(b, 0, sizeof(b));
		for(int j = 0; j < n; j++)
		{
			scanf("%d %d %d", &a[j][0], &a[j][1], &a[j][2]);
		}
		for(int k = 1 ; k < n; k++)
		{
			for(int j = k - 1; j >= 0; j--)
			{
				for(int l = 0; l < k; l++)
			{
				b[k-j][k-l][k] = x_max(a[k][0]+(b[k-j-1][k-l][k]),b[k-j][k-1-l][k]+a[k][1],b[k-j][k-l][k-1]+a[k][2]);
				b[k][k-j][k-l] = x_max(a[k][0]+(b[k-1][k-j][k-l]),b[k][k-1-j][k-l]+a[k][1],b[k][k-j][k-1-l]+a[k][2]);
				b[k-l][k][k-j] = x_max(a[k][0]+(b[k-1-l][k][k-j]),b[k-l][k-1][k-j]+a[k][1],b[k-l][k][k-1-j]+a[k][2]);
			}}
			
		}
		cout << (b[n-1][n-1][n-1]) << endl;
	}
	return 0;
}
