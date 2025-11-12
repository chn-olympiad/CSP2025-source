#include<bits/stdc++.h>
#define ll long long
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int M = 998244353;
int n, m, c[505], ans = 1;
string s;
vector<int> v;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	_for(i, 1, n){
		cin >> c[i];
		if(c[i]) v.push_back(c[i]);
	}
	_for(i, 1, m) (ans *= i) %= M;
	cout << ans;
	return 0;
}