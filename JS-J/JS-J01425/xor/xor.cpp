#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n;
	ll k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll maxn=1LL;
	for(ll i=1;i<=n;i++){
		ll l=a[i],r=i+1,cnt=0;
		for(ll j=i+1;j<=n;j++){
			l^=a[r];
			if(l==k){
				cnt++;
				l=a[r+1];
				r+=2;
			}
			else r++;
		}
		maxn=max(maxn,cnt);
	}
		cout<<maxn;
	}
	return 0;
}