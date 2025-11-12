#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
constexpr int M1 = 998244353, M2 = 1e9 + 7;
#define sec second
#define fir first

ll qpow(ll a, ll b, ll m){
	ll res = 1;
	while(b){
		if(b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b){
	while(b)
		b ^= a ^= b ^= a %= b;
	return a;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	string s1;
	cin >> s1;
	vector <int> nums;
	for(auto i : s1)
		if(isdigit(i))
			nums.push_back(i - 48);
	sort(nums.begin(), nums.end());
	for(int i = nums.size() - 1; i >= 0; i--)
		cout << nums[i];
	return 0;
}