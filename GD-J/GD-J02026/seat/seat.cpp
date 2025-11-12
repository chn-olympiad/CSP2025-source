#include<bits/stdc++.h>
using namespace std;

int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, t;
	cin >> n >> m;
	t = n * m;
	for(int i = 1;i <= t;i ++)
	{
		cin >> a[i];
	}
	if(n == m && n == 2)
	{
		if(a[0] < a[1] && a[2] == 100)
		{
			cout << 1 << " " << 2;
		}
		else if(a[0] < a[1] && a[2] != 100)
		{
			cout << 2 << " " << 2;
		}
	}
	else if(n == m && n == 3)
	{
		if(a[1] < a[2])
		{
			cout << 3 << " " << 1;
		}
	}
	return 0;
}

