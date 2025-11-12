#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define SZ(x) ((x).size())
#define rep(i,l,r) for(int i = (l);i <= (r);i++)
#define per(i,l,r) for(int i = (r);i >= (l);i--)
#define fi first
#define se second
#define pb push_back
#define F(x) ((x) % P)
#define FE(x) ((x) %= P)
using namespace std;
using ll = long long;
using db = double;
using PII = pair<int,int>;
using PLL = pair<ll,ll>;
constexpr ll infL = 1ll << 30;
constexpr int infI = 1 << 30;

const int P = 998244353;

int a[510];

ll ans;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	string s;
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	rep(i,1,n) cin >> a[i];
	if(n == m){
		rep(i,1,n){
			if(s[i] == '0') return cout << 0,0;
		}
		rep(i,1,n){
			if(a[i] == 0) return cout << 0,0;
		}
		ll res = 1;
		rep(i,1,n){
			FE(res *= i);
		}
		printf("%lld",res);
		return 0;
	}
	vector<int> p;
	rep(i,1,n) p.pb(i);
	do{
		int t = 0;
		rep(i,1,n){
			if(t >= a[p[i - 1]]  || s[i] == '0'){
				t++;
			}
		}
		if(n - t >= m) ans++;
		FE(ans);
	}while(next_permutation(all(p)));
	printf("%lld\n",ans);
	return 0;
}