#include<bits/stdc++.h>
#define ll long long
#define N 20
using namespace std;
ll n,m;
ll a[N*N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1; i<=n*m; i++)
		cin>>a[i];
	ll u=a[1],v=n*m+1;
	sort(a+1,a+n*m+1);
	for(ll i=1; i<=m; i++) {
		if(i%2!=0) {
			for(ll j=1; j<=n; j++) {
				v--;
				if(a[v]==u) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
		} else {
			for(ll j=n; j>=1; j--) {
				v--;
				if(a[v]==u) {
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
2 2
99 100 97 98
*/