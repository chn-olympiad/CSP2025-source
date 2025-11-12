#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin >> n >> k;
	for(ll i = 1;i <= n;i++) cin >> a[i];
	if(n==1&&k==0) cout << 1;
	else if(n==2&&k==0){
		if((a[1]^a[1])==(a[2]^a[2])&&(a[2]^a[2])==(a[1]^a[2])) cout << 3;
		else if((a[1]^a[1])==(a[2]^a[2])||(a[2]^a[2])==(a[1]^a[2])||(a[1]^a[1])==(a[1]^a[2])) cout << 2;
		else cout << 1;
	}
	return 0;
}
