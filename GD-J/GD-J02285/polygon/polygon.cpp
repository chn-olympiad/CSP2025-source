#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],mx,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		mx = max(mx,a[i]);
	}
	ll cnt = 1;
	for(int i = 1;i <= n;i++){
		cnt *= i;
	}
	if(mx == 1){
		for(int i = 3;i <= n;i++){
			ll cnt1 = 1;
			for(int j = 1;j <= i;j++){
				cnt1 *= j;
			}
			ans += cnt / cnt1;
			ans %= 998244353;
		}
		cout << ans % 998244353;
	}else if(n == 3){
		ll sum = a[1] + a[2] + a[3];
		if(sum > mx * 2) cout << 1;
		else cout << 0;
	}
	fclose(stdin);
	return 0;
}
