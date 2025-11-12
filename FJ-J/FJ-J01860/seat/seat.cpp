#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005],f[105][105],cnt = 1;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	    cin >> a[i];
	int ans = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for (int j = 1;j <= m;j++)
	{
		if (j % 2 == 1)
		{
			for (int i = 1;i <= n;i++)
			    f[i][j] = a[cnt++];
		}
		else
		{
			for (int i = n;i >= 1;i--)
			    f[i][j] = a[cnt++];
		}
	}
	for (int i = 1;i <= n;i++)
	    for (int j = 1;j <= m;j++)
	        if (f[i][j] == ans) cout << j << " " << i << endl;
}
