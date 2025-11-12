#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e5 + 66;
ll n, q;
struct ue{
	string s, s1;
	ll lef, rig, lef1, rig1;
}s[N], qq[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i ++)
	{
		 cin >> s[i].s >> s[i].s1;
	}
	for(int i = 1;i <= q;i ++)
	{
		cin >> qq[i].s >> qq[i].s1;
		if(qq[i].s == qq[i].s1) cout << n << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}

