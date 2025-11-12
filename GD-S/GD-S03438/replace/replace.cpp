#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+7, M = 5e6+7, bs = 711, nbs = 423782;
const int bs2 = 452, nbs2 = 638745;
const int mod = 301309001, mod2 = 288712739;
int n, q;
int kc(int x){
	if(x >= mod) return x-mod;
	return x;
}
int kc2(int x){
	if(x >= mod2) return x-mod2;
	return x;
}
struct uct{
	int x, y;
	bool operator <(const uct v)const{
		if(x == v.x) return y < v.y;
		return x < v.x;
	}
	uct operator -(const uct v)const{
		return (uct){kc(x-v.x+mod), kc2(y-v.y+mod2)};
	}
};
map<uct, int> mp;
string s;
int fc[26];
uct hash_r(){
	int len = s.size();
	uct sum = (uct){0, 0};
	uct t = (uct){1, 1};
	for(int i = 0; i < len; i++){
		sum.x = kc(1ll*t.x*fc[s[i]-'a']%mod+sum.x);
		t.x = 1ll*t.x*bs%mod;
		sum.y = kc2(1ll*t.y*fc[s[i]-'a']%mod2+sum.y);
		t.y = 1ll*t.y*bs2%mod2;
	}
//	cout << "??" << sum << '\n';
	return sum;
}
signed main(){
	//is long long?
	//The N is enough?
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	srand(time(0));
	for(int i = 0; i < 26; i++) fc[i] = rand()*32767+rand();
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s;
		uct us = hash_r();
		cin >> s;
		us = us-hash_r();
//		cout << i;
//		cout << ' '<< us.x << ' ';
//		cout << us.y << ' ' << mp[us] << '\n';
//		assert(mp[us] == 0);
		mp[us]++;
//		cout << kc(us-hash_r()+mod) << '\n';
	}
	assert(bs*nbs%mod == 1);
	assert(bs2*nbs2%mod2 == 1);
	while(q--){
		cin >> s;
		uct us = hash_r();
		cin >> s;
		us = us-hash_r();
		int ans = 0;
		for(int i = 0; i < s.size(); i++){
			ans += mp[us];
//			cout << us.x << '/' << us.y << ' ';
			us.x = 1ll*us.x*nbs%mod;
			us.y = 1ll*us.y*nbs2%mod2;
		}
		cout << ans << '\n';
	}
	return 0;
} 
