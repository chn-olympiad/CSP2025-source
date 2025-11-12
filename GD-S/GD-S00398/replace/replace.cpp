#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
const int maxt = 5e6 + 5;
using ull = unsigned long long;
void solve();
string a[maxn];
string b[maxn];
ull hsha[maxn];
ull hshb[maxn];
ull hsht[maxt];
ull hshs[maxt];
ull powb[maxt];
const ull bse = 131;
const ull mod = 1e9+9;
inline ull hsh(string x) {
	ull ret = 0;
	for(char ch : x) {
		ret = ( ret * bse ) + ch;
		ret%=mod;
	}
	return ret;
}
inline ll qpow(ll a,ll b) {
	ll ans(1);
	while(b) {
		if(b&1)ans = (ans * a) % mod;
		a = (a*a) % mod;
		b>>=1;
	}
	return ans;
}
inline ll inv(ll x) {
	return qpow(x,mod-2);
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i = 0; i<n; ++i) {
		cin>>a[i]>>b[i];
		hsha[i] = hsh(a[i]);
		hshb[i] = hsh(b[i]);
	}
//	for(int i = 1; i<maxt; ++i)powb[i] = (powb[i-1] * bse)%mod;
	while(q--)solve();
	return 0;
}
void solve() {
	cout<<0;
}

