#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 5e3+5;
const ull MOD = 998244353;
ull n;
ull sticks[N];

ull ans;

ull C(int n,int m) {
	// return n! / (m!*(n-m)!)
	ull ret = 1*2*3*4*5*6*7*8*9*10;
	for(int i=11;i<=n;i++) {
		ret = ret * i / (i-10<=m ? i-10 : 1) / (i-10<=(n-m) ? i-10 : 1) % MOD;
	}
	return ret;
}

void dfs(ull step,ull st,ull cnt,ull sum,ull mx) {
	if(cnt >= step) {
		if(sum > 2*mx) {
			++ans;
		}
		ans %= MOD;
		return;
	}
	
	for(ull i=st+1;i<=n;++i) {
		dfs(step,i,cnt+1,sum+sticks[i],max(mx,sticks[i]));
	}
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	bool a_cut = true;
	for(ull i=1;i<=n;i++) {
		cin>>sticks[i];
		if(sticks[i] != 1) a_cut = false;
	}
	
	// 40pts -> enum
	
	// 64 pts -> cut
	// according to the question ,there's a situation that all the number is "1"
	if(a_cut && n>=10) {
		for(ull i=3;i<=n;++i) {
			ans = (ans + C(n,i)) % MOD;
		}
	}
	else {
		for(ull i=3;i<=n;i++) {
			dfs(i,0,0,0,INT_MIN);
		}
	}
	
	cout<<ans%MOD;
	return 0;
}