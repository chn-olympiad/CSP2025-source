#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
ll n,k,ans;
ll a[N],c[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		c[i]=c[i-1]^a[i];
	}
	ll p=1;
	for(ll i=1; i<=n; i++) {
		for(ll j=p; j<=i; j++)
			if((c[i]^c[j-1])==k) {
				ans++;
				p=i+1;
				break;
			}
	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3
*/