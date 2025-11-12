#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20;

int n, m;

struct node
{
	int x, id;
	bool operator<(const node &o) const { return x > o.x;}
}a[MAXN * MAXN];

int c[MAXN][MAXN];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].x, a[i].id = i;
	sort(a+1, a+n*m+1);
	int x = 1, y = 1;
	for(int i=1;i<=n*m;i++)
	{
		c[x][y] = a[i].id;
		if(a[i].id == 1)
		{
			cout<<x<<' '<<y;
			return 0;
		}
		if(x % 2 == 1 && y < m) y++;
		else if(x % 2 == 0 && y > 1) y--;
		else if(x % 2 == 1 && y == m) x++;
		else if(x % 2 == 0 && y == 1) x++;
	}
	return 0;
}
