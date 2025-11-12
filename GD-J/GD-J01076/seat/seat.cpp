#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int p[100];
	for (int i = 1;i <= n * m;i++) cin >> p[i];
	int goa = p[1];
	sort(p+1,p+m*n+1);
	float flag;
	for (int i = 1;i <= n*m;i++) if (p[i] == goa) {flag = n * m - i + 1;break;}
	cout << ceil(flag / n) << ' ';
	if (m % 2 == 0) cout << n+1-(flag - (flag - 1) / m * m);
	else cout << flag - (flag-1) / m * m;
	return 0;
}
