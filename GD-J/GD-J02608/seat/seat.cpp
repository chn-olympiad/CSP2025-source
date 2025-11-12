#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+5;

ll n,m;
int g[N];
ll cnt;
ll goal;
ll x,y;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cnt++;
	cin >> g[cnt];
	goal = g[cnt];
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> g[++cnt];
		}
	}
	sort(g+1,g+cnt+1,cmp);
	for(int i = 1;i <= cnt;i++)
	{
		if(g[i] == goal)
		{
			goal = i;
			break;
		}
	}
	x = ceil((double)goal / n);
	y = goal % n;
	if(!y) y=n;
	if(x % 2 == 0)
		y = n - y + 1;
	cout << x << ' ' << y;
	return 0;
}
