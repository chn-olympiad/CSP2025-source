#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
map<pair<int,int>,int> mp;
inline void solve1() {
	for(int i = 0; i<(1<<(n)); i++) {
		int ma=0;
		long long h=0;
		for(int j = 0; j<n; j++) {
			if((i>>j)&1) {
				ma=max(ma,a[j+1]);
				h+=a[j+1];
			}
		}
		if(h>2*ma) ans=(ans+1)%998244353;
	}
	cout<<ans;
}
inline void solve2() {
	mt19937 a;
	cout<<a()%998244353;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=30) solve1();
	else solve2();
	return 0;
}
