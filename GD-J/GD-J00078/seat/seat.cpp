#include<bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,j;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
		cin >> a[i];
	int a1 = a[1];
	sort(a + 1,a + n * m + 1);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == a1)
		{
			j = n * m - i + 1;
			break;
		}
	}
	if(j % (2 * n) > n) cout << j / (2 * n) * 2 + 2 << ' ' << n - (j % (2 * n) - n) + 1;
	else cout << j / (2 * n) * 2 + 1 << ' ' << j % (2 * n);
	return 0;
} 
