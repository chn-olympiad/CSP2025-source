#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int n,m,a[maxn],x,num,h,l;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
		cin >> a[i];
	x = a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1; i <= n*m; i++)
		if (a[i] == x)
		{
			num = i;
			break;
		}
	if (num % n == 0) l = num/n;
	else l = num/n+1;
	if (l % 2 == 0) h = l*n+1-num;
	else h = n-(l*n-num);
	cout << l << ' ' << h << endl;
	return 0;
}
