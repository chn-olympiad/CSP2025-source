#include <bits/stdc++.h>
using namespace std;

int a[101];

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> a[i];
	}
	int r=a[1];
	sort(a+1, a+1+n*m, cmp);
	int now=0;
	for (int i = 1; i <= n*m; i++)
	{
		if (a[i]==r) now=i;
	}
	int lie, hang;
	lie=ceil(1.0*now/n);
	cout << lie << " ";
	if (lie%2==1)//正向 
	{
		hang=now%n;
		if (hang==0) hang=n;
		cout << hang;
	}
	else//反向 
	{
		hang=now%n;
		if (hang==0) hang=n;
		cout << n-hang+1; 
	}
	return 0;
}
