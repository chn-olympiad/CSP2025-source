#include <bits/stdc++.h>
using namespace std;

const int N = 10 + 5;
struct Node
{
	int id;
	int f;
	void read()
	{
		cin >> f;
	}
}a[N * N];

bool cmp(Node x, Node y)
{
	return x.f > y.f;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		a[i].read();
		a[i].id = i;
	}
	int cnt = 0;
	sort(a + 1, a + n * m + 1, cmp);
//	for(int i = 1; i <= n * m; i++)
//	{	
//		cout << a[i].f << " " << a[i].id << endl;;	
//	}
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i].id == 1)
		{
			cnt = i;
			break;
		}
	}
//	cout << cnt;
	if(cnt % n == 0)
	{
		int mc = cnt / n;
		if(mc % 2 == 0)
		{
			cout << 1 << " " << mc << endl;
			return 0;
		}
		else
		{
			cout << mc << " " << n << endl;
			return 0;
		}
	}
	else
	{
		int mc = cnt / n + 1;
		int cm = cnt % n;
		if(mc % 2 == 0)
		{
			cout << n - cm + 1 << " " << mc << endl;
			return 0;
		}
		else
		{
			cout << mc << " " << cm << endl;
			return 0;
		}
	}
	return 0;
}
