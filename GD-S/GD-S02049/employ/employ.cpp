#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string s;
ll a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	ll ans = 1;
	for(int i = n;i >= 1;i--){
		ans *= i;
		ans %= 998244353;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
