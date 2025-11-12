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
constexpr ll infL = 1ll << 60;
constexpr int infI = 1 << 30;

const int N = 1e5 + 10;

int T;

int n;

ll a[N][5];

PLL b[N];

ll calc(){
	ll ans = 0;
	sort(b + 1,b + 1 + n,[](PLL x,PLL y){
		return x.fi - x.se > y.fi - y.se;
	});
	rep(i,1,n / 2){
		ans += b[i].fi;
	}
	rep(i,n / 2 + 1,n){
		ans += b[i].se;
	}
	return ans;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ll ans = -infL;
		rep(i,1,n) rep(j,1,3) scanf("%lld",&a[i][j]);
		rep(i,1,n) b[i].fi = a[i][1],b[i].se = max(a[i][2],a[i][3]);
		ans = max(ans,calc());
		rep(i,1,n) b[i].fi = a[i][2],b[i].se = max(a[i][1],a[i][3]);
		ans = max(ans,calc());
		rep(i,1,n) b[i].fi = a[i][3],b[i].se = max(a[i][1],a[i][2]);
		ans = max(ans,calc());
		int x = 0,y = 0,z = 0;
		ll res = 0;
		rep(i,1,n){
			int t = max({a[i][1],a[i][2],a[i][3]});
			if(t == a[i][1]){
				x++;
			}else if(t == a[i][2]){
				y++;
			}else{
				z++;
			}
			res += t;
		}
		if(x <= n / 2 && y <= n / 2 && z <= n / 2) ans = max(ans,res);
		printf("%lld\n",ans);

	}
	return 0;
}