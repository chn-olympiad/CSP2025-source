#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],sum[500010],last,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=last; j<i; j++){
			if((sum[i] ^ sum[j]) == k){
				last = i;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
