#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
ll n;
ll a[5005],ans;
bool vis[5005];
bool flg = 1;
bool check2(ll mx,ll num,ll en){
	ll sm = 0,ct = 0;
	for(int i = 1;i <= en && ct != num;i++){
		if(vis[i]){
			sm += a[i];
			ct++;
		}
	}
	if(sm > 2 * mx) return true;
	else return false;
}
ll solve2(ll mx,ll num,ll cnt,ll la){
	ll ans = 0;
	if(cnt == num){
		return check2(mx,num,la);
	}
	for(int i = la+1;i <= n - num + cnt + 1;i++){
		vis[i] = 1;
		ans = (ans + solve2(max(mx,a[i]),num,cnt+1,i)) % mod;
		vis[i] = 0;
	}
	return ans % mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] > 1) flg = 0;
	}
	if(n < 3){
		cout<<0<<endl;
	}
	else if(flg){
		//排列组合
		ans = 1;
		for(int i = 3;i < n;i++){
			ll x = 1,y = 1;
			ll c = max(2*i-n,(ll)0);
			for(int j = n;j > n - i + c;j--) x *= j;
			for(int j = i - c;j > 1;j--) y *= j;
			ans += (x / y) % mod;
			ans %= mod;
		}
	}
	else{
		sort(a+1,a+n+1);
		for(int i = 3;i <= n;i++){
			ans = (ans + solve2(0,i,0,0)) % mod;
		}
	}
	cout<<ans % mod<<endl;
	return 0;
}