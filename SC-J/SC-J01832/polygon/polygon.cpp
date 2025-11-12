#include <bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
int mod = 998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if (n<3) {
		cout << 0;
		return 0;
	}
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for (int i = 1;i<=n;i++){
		if (a[i]+a[i+1]+a[i+2]>2*a[i+2]){
			ans++;
		}
		if (a[i]+a[i+1]+a[i+2]+a[i+3]>2*a[i+3]){
			ans++;
		}
		if (a[i]==a[i+1]) ans-=2;
	}
	cout << ans%mod;
}