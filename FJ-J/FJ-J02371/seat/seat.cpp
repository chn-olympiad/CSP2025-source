#include<bits/stdc++.h>
using namespace std;
const int N = 105;

int n, m, t;
int a[N];
priority_queue<int > q;

//窝要上迷惑行为大赏！！！
//saet
//这题也很简单
//开T3喽
//I LOVE CCF FOR EVER!!! 

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)cin >> a[i];
	t = a[1];
	for(int i = 1; i <= n * m; i++)q.push(a[i]);
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(q.top() == t)
			{
				if(i % 2 == 0)
				{
					cout << i << ' ' << n - j + 1;
				}
				else
				{
					cout << i << ' ' << j;
				}
				return 0;
			}
			q.pop();
		}
	}
	
	return 0;
}
