#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[114];
int s[20][20];

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	int x = a[1];
	sort(a + 1,a + n * m + 1);
	reverse(a + 1,a + n * m + 1);
	for (int i = 1;i <= m;i += 2)
		for (int j = 1;j <= n;j++)
			s[j][i] = a[i == 1 ? j : ((i / 2) * 2 * n + j)];
	for (int i = 2;i <= m;i += 2)
		for (int j = 1;j <= n;j++)
			s[j][i] = a[i * n - j + 1];
//	for (int i = 1;i <= n;i++){
//		for (int j = 1;j <= m;j++) cout << s[i][j] << " ";
//		cout << endl;
//	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (s[i][j] == x){cout << j << " " << i << endl; return 0;}

	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

*/
