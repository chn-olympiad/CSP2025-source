#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
struct Per
{
	ll a, b, c;
}p[N];
bool cmp1(Per xx, Per yy)
{
	if(xx.a != yy.a)
		return xx.a > yy.a;
	return (xx.b > yy.b && xx.b > yy.c) || (xx.c > yy.b && xx.c > yy.c);
}
int T, n;
ll res;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		memset(p, 0, sizeof(p));
		res = 0;
		for(int i = 1; i <= n; i++)
			cin >> p[i].a >> p[i].b >> p[i].c;
		sort(p + 1, p + n + 1, cmp1);
		for(int i = 1; i <= n / 2; i++)
		{
			ll j = i + n / 2;
			ll tmpa = p[i].a + max(p[j].b, p[j].c), tmpb = p[i].b + max(p[j].a, p[j].c), tmpc = p[i].c + max(p[j].a, p[j].b);
			if(tmpa >= tmpb && tmpa >= tmpc)
				res += tmpa;
			else if(tmpb >= tmpa && tmpb >= tmpc)
				res += tmpb;
			else
				res += tmpc;
		}
		cout << res << '\n';
	}
	return 0;
}
