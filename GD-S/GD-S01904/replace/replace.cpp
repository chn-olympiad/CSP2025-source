#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int hs = 249;
const int maxn = 5000005;
const int inf = 998244353;
map<long long, int> mp;
long long p[maxn], x[maxn], y[maxn];
int g(int l, int r){
	return (x[r] - x[l - 1] * p[r - l + 1] % inf + inf) % inf;
}
int gg(int l, int r){
	return (y[r] - y[l - 1] * p[r - l + 1] % inf + inf) % inf;
}
long long id(long long a, long long b){
	return b * 999999999 + a;
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	p[0] = 1;
	for(int i = 1;i < maxn;i++) p[i] = p[i - 1] * hs % inf;
	for(int i = 1;i <= n;i++){
		string s, s1;
		cin >> s >> s1;
		int len = s.length();
		long long sum = 0, sum1 = 0;
		for(int j = 0;j < len;j++){
			sum = sum * hs + s[j] - 'a' + 1;
			sum %= inf;
			sum1 = sum1 * hs + s1[j] - 'a' + 1;
			sum1 %= inf;
		}
		// cout << sum << ' ' << sum1 << endl;
		mp[id(sum, sum1)]++;
	}
	for(int i = 1;i <= m;i++){
		string s, s1;
		cin >> s >> s1;
		int len = s.length(), ans = 0;
		for(int j = 1;j <= len;j++){
			x[j] = x[j - 1] * hs + s[j - 1] - 'a' + 1;
			x[j] %= inf;
			y[j] = y[j - 1] * hs + s1[j - 1] - 'a' + 1;
			y[j] %= inf;
		}
		for(int l = 1;l <= len;l++){
			for(int r = len;r >= l;r--){
				long long pp = g(l, r), pp1 = gg(l, r);
				if(mp.count(id(pp, pp1))){
					// cout << l << ' ' << r << ' ' << pp << ' ' << pp1 << endl;
					ans += mp[id(pp, pp1)];
				}
				if(s[r - 1] != s1[r - 1]) break;
			}
			if(s[l - 1] != s1[l - 1]) break;
		}
		cout << ans << "\n";
	}
	return 0;
}