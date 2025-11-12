#include<bits/stdc++.h>
#define ll long long
#define _for(i, a, b) for(ll i = (a); i <= (b); ++i)
using namespace std;
ll n, k, a[500005], s[500005], mx, ans;
unordered_map<ll, ll> m;
vector<pair<int, int>> v, nv;
bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if(n == 1){
		int a;
		cin >> a;
		if(a == k) ans++;
		return cout << ans, 0;
	}
	m[0] = 0;
	_for(i, 1, n){
		cin >> a[i], s[i] = s[i - 1] ^ a[i], m[s[i]] = i;
		ll t = m[s[i] ^ k];
		if((t || !(s[i] ^ k)) && t < i) v.push_back({t + 1, i});
		if(a[i] == k) v.push_back({i, i});
	}
	sort(begin(v), end(v));
	v.push_back({1e9, 1e9});
	_for(i, 0, (int)v.size() - 2){
		if(v[i].first <= mx) continue;
		if(v[i].second < v[i + 1].second) mx = v[i].second, ans++;
	}
	cout << ans;
	return 0;
}