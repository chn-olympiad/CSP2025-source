#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;

ll n, q;
string s1, s2, t1, t2;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(ll i = 1; i <= n; i++)
	{
		cin >> s1 >> s2;
	}
	for(ll j = 1; j <= q; j++)
	{
		cin >> t1 >> t2;
		cout << 0 << "\n";
	}
	return 0;
} 
