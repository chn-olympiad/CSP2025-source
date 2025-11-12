#include <bits/stdc++.h>

using namespace std;

int ar[105];

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	cin >> ar[0];
	int t = ar[0];
	for (int i = 1;i < n * m;i++)
	{
		cin >> ar[i];
	}
	sort(ar,ar + n * m,cmp);
	for (int i = 0;i < n * m;i++)
	{
		if (ar[i] == t)
		{
			t = i;
			break;
		}
	}
	
	int c = ceil((t + 1) * 1.0 / m);
	int r = (t % n) + 1;
	if (c % 2 == 0)
	{
		r = n + 1 - r;
	}
	cout << c << ' ' << r;
	return 0;
}
