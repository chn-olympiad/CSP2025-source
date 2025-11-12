#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fr(a,b,c) for(c=a;c<=b;c++)
#define rf(a,b,c) for(c=a;c>=b;c--)
#define I_AK_CSP 0
#define MAXN 1000001
string s;
ll n, m, book[MAXN], i, j, k;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	fr(0, n - 1, i)
	{
		fr(1, m, j)
		{
			cin >> book[i * m + j];
		}
	}
	k = book[1];
	sort(book + 1, book + n * m + 1);
	rf(n * m, 1, i)
	{
		if(book[i] == k)
		{
			ll ls, x, y;
			ls = n * m - i + 1;
			x = ceil(ls * 1.0 / n);
			if(x & 1)
			{
				y = ls % n;
			}
			else
			{
				y = n - ls % n +1;
			}
			if(!y)y += n;
			if(y==n+1) y -= n;
			cout << x << " " << y;
			return I_AK_CSP;
		}
	}
	return I_AK_CSP;
}
