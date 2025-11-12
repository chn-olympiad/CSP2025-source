#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int a[105];

bool cmp(const int &l, const int &r)
{ return l > r; }

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	int tmp = a[1], id;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++)
		if(a[i] == tmp)
		{
			id = i;
			break;
		}
	int c = (id - 1) / n, r;
	if(c % 2 == 0) r = id - c * n;
	else
	{
		id -= n, c--;
		r = id - c * n;
		r = n - r + 1;
		c++;
	}
	cout << c + 1 << " " << r << endl;
	return 0;
}
