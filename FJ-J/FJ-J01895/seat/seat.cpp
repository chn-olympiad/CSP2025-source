#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int R;
	cin >> R;
	int a;
	int s = 1;
	bool flag = false;
	for(int i = 0;i < n * m - 1;i++)
	{
		cin >> a;
		if(a > R)
			s++;
	}
	for(int i = 1;i < m;i = i + 2)
	{
		for(int j = 1;j <= n;j++)
		{
			if(i * n + j == s) 
			{
				flag = true;
				break;
			}
			if(2 * i * n + j == s)
			{
				flag = false;
				break;
			}
		}
	}
	if(!flag)
	{
		if(s % n == 0)
			cout << s / n << ' ';
		if(s % n != 0)
			cout << s / n + 1 << ' ';
		if(s % n == 0)
			cout << n;
			
		if(s % n != 0)
			cout << s % n;
	}
	else
	{
		if(s % n == 0)
		{
			cout << s / n << ' ';
			cout << 1;
		}
			
		if(s % n != 0)
		{
			cout << s / n + 1 << ' ';
			cout << (s / n + 1) * n - s + 1;
		}
			
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
