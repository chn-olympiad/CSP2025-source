#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1005;

ll n, m;
ll a[N];
ll c, r, x;

bool cmp(ll x, ll y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	ll tmp = n * m;
	for(int i = 1; i <= tmp; i++)
	{
		cin >> a[i];
	}
	ll tmpp = a[1];
	sort(a + 1, a + 1 + tmp, cmp);
	for(int i = 1; i <= tmp; i++)
	{
		if(a[i] == tmpp)
		{
			ll xx = i;
			if(xx % n == 0)
			{
				c = xx / n;
			}
			else
			{
				c = xx / n + 1;
				
			}
			r = xx % n;
			if(c % 2 == 1)
			{
				cout << c << " ";
				if(r == 0)
				{
					cout << n; 
				}
				else
				{
					cout << r;
				}
			}
			else
			{
				cout << c << " " << n - r + 1;
			}
			return 0;
		}
	}
	return 0;
}
