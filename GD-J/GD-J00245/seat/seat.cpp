#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n , m;
struct node{
	int num , id;
};
node a[N];
int ans[N][N];
bool cmp(node x , node y)
{
	return x.num > y.num;
}
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i)
	{
		cin >> a[i].num;
		a[i].id = i;
	}
	int cnt = 0;
	sort(a + 1 , a + 1 + n * m , cmp);
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			++cnt;
//			cout << a[cnt].num << endl; 
			if (a[cnt].id == 1)
			{
				if (i % 2 == 0)
				{
					cout << i << " " << n - j + 1;
					return 0;
				}else
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
3 3
111 95 96 97 98 99 100 93 92

100 97 94
99  96 93
98  95 92
*/
