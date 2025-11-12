#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long n,m,a[103],num = 1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
		if(a[i] > a[1])
		{
			num++;//µÚ¼¸Ãû 
		}
	}
	if(num % (n * 2) >= 1 and num % (n * 2) <= n)
	{
		cout << (num / n) + 1 << " ";
		if(num % n != 0)
		{
			cout << num % n;
		}
		else
		{
			cout << n;
		}
	}
	else
	{
		cout << (num / n) + 1 << " ";
		if(num % n != 0)
		{
			cout << m - (num % n) + 1;
		}
		else
		{
			cout << 1;
		}
	}
	return 0;
}
