#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fr(a,b,c) for(c=a;c<=b;c++)
#define rf(a,b,c) for(c=a;c>=b;c--)
#define I_AK_CSP 0
#define MAXN 2000001
ll n, a[MAXN], k, i;
void nb(ll x, ll h)
{
	for(int i = x + 1; i <= n; i++)
	{
		if(h > a[i])
		{
			k++;
			k%=998244353;
		}
		nb(i, h + a[i]);
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	fr(1, n, i)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	nb(0, 0);
	cout << k;
	return I_AK_CSP;
}
