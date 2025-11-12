#include <bits/stdc++.h> 
using namespace std;

#define int long long

int a[205];

bool cmp(int x,int y)
{
	return x > y;
}

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xxnum,id;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
		if(i == 1)
		{
			xxnum = a[i];
		}
	}
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == xxnum)
		{
			id = i;
			break;
		}
	}
	int sum = id / n + (id % n > 0);
	int k = id % n;
//	cout << id << " " << k << "\n";
	if(sum % 2 == 0)
	{
		cout << sum << " " << n - k + 1;
	}
	else
	{
		cout << sum << " " << k + n * (k == 0);
	}
	return 0;
}