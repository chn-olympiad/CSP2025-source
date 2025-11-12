#include <bits/stdc++.h>
using namespace std;

int ch[1005];

bool cmp(int x , int y)
{
	return x > y;
}

int main()
{
	freopen(seat.in , "r" , stdin);
	freopen(seat.out , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> ch[i];
	}
	int x = ch[1];
	sort(ch + 1 , ch + n * m + 1 , cmp);
	int cnt = 0;
	for(int j = 1; j <= m; j++)
	{
		if(j % 2 == 1)
		{
			for(int i = 1; i <= n; i++)
			{
				cnt++;
				if(ch[cnt] == x)
				{
					cout << j << " " << i;
					return 0;
				}
			}
		}
		else
		{
			for(int i = n; i >= 1; i--)
			{
				cnt++;
				if(ch[cnt] == x)
				{
					cout << j << " " << i;
					return 0;
				}
			}
		}
	}
	return 0;
 } 
