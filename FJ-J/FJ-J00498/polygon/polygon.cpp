#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll n,num[10000];
ll ans;

ll C(ll n,ll m){
	ll answ = 1;
	for(int i = n;i>n-m;i--){
		answ = (answ*i) % mod;
	}
	for(int i = m;i>0;i--){
		answ /= i;
	}
	return answ;
}
ll dfs(ll de,ll ma,ll a, ll side){
	if(de == n){
		if(side < 3) return 0;
		if(ma * 2 >= a) return 0;
		else return 1;
	}
	else return dfs(de+1,ma,a,side) + dfs(de+1,num[de],a + num[de],side+1);
}
void solve()
{
	cin >> n;
	bool flag = true;
	for(int i = 0;i<n;i++){
		scanf("%lld",&num[i]);
		if(num[i] != 1) flag = false;
	}sort(num,num+n);
	
	if(n <= 2){
		cout << 0;
		return;
	}
	if(n == 3){
		if(num[0] +num[1] > num[2]) cout <<1;
		else cout << 0;
		return;
	}
	if(flag){
		for(int i = 3;i<=n;i++){
			ans = (ans + C(n,i)) % mod;
		}
	}else{
		ans  = dfs(0,0,0,0);
	}
	cout << ans;
}

int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	solve();
	return 0;
}
