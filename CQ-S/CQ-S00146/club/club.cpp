#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100005;
struct whz {
	ll x, y, z, id;
} a[N];
int n, X, Y, Z;
ll ans;//, wh;
bool cx(whz x, whz y) { return x.x-max(x.y, x.z) < y.x-max(y.y, y.z); }
bool cy(whz x, whz y) { return x.y-max(x.x, x.z) < y.y-max(y.x, y.z); }
bool cz(whz x, whz y) { return x.z-max(x.y, x.x) < y.z-max(y.y, y.x); }
ll mx(ll x, ll y, ll z) { return (x>y?x:y)>z?(x>y?x:y):z; }
ll ma(ll x, ll y) { return x>y?x:y; }

void sol() {
	X=Y=Z=0;
	ans = 0;// wh = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) {
		scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
//		wh += max({a[i].x, a[i].y, a[i].z}); 
		if(a[i].x == mx(a[i].x, a[i].y, a[i].z)) {
			++X;
			ans+=a[i].x;
			a[i].id=1;
		}else if(a[i].y == mx(a[i].x, a[i].y, a[i].z)) {
			++Y;
			ans+=a[i].y;
			a[i].id=2;
		}else if(a[i].z == mx(a[i].x, a[i].y, a[i].z)) {
			++Z;
			ans+=a[i].z;
			a[i].id=3;
		}	
	}
	if(X<=n/2 && Y<=n/2 && Z<=n/2) {
		printf("%lld\n", ans);
		return ;
	}
//	cout<<"0:"<<X<<' '<<Y<<' '<<Z<<endl;
	if(X > n/2) {
		sort(a+1, a+1+n, cx);
		for(int i=1; i<=n&&X>n/2; ++i) {
			if(a[i].id == 1) {
				--X;
				ans -= (a[i].x-ma(a[i].y, a[i].z));
				if(a[i].y>a[i].z)
					a[i].id = 2, ++Y;
				else a[i].id = 3, ++Z;
			}
		}
//		printf("%lld\n", ans);
	}
//	cout<<"x:"<<X<<' '<<Y<<' '<<Z<<endl;
	if(Y > n/2) {
		sort(a+1, a+1+n, cy);
		for(int i=1; i<=n&&Y>n/2; ++i) {
			if(a[i].id == 2) {
				--Y;
				ans -= (a[i].y-ma(a[i].x, a[i].z));
				if(a[i].x>a[i].z)
					a[i].id = 1, ++X;
				else a[i].id = 3, ++Z;
			}
		}
//		printf("%lld\n", ans);
	}
//	cout<<"y:"<<X<<' '<<Y<<' '<<Z<<endl;
	if(Z > n/2) {
		sort(a+1, a+1+n, cz);
		for(int i=1; i<=n&&Z>n/2; ++i) {
			if(a[i].id == 3) {
				--Z;
				ans -= (a[i].z-ma(a[i].y, a[i].x));
				if(a[i].y>a[i].x)
					a[i].id = 2, ++Y;
				else a[i].id = 1, ++X;
			}
		}
	}
//	cout<<"z:"<<X<<' '<<Y<<' '<<Z<<endl;
//	if(X>n/2 || Y>n/2 || Z>n/2) {
//		puts("???");
//	}
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--) sol();
	return 0;
}
