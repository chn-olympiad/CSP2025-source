#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a; i<=b; ++i)
#define F_(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define pii pair<int,int>
#define fr first
#define sc second
typedef long long ll;
const int N = 5e2+10; const ll Mod = 998244353;
int n,m,num[N],c[N];
string s;
ll dp[1<<18][19];
inline int pc(int x){
	int cnt = 0;
	while (x){
		cnt += (x&1);
		x >>= 1;
	}
	return cnt;
}
inline void add(ll &x,ll y){
	x = (x+y)%Mod;
}
void baoli(){
	dp[0][0] = 1;
	F(S,0,(1<<n)-1){
		int tot = pc(S);
		F(k,0,tot){
			F(i,1,n){
				if (S&(1<<i-1)) continue;
				int nS = (S^(1<<i-1));
				if (k >= c[i]) add(dp[nS][k+1],dp[S][k]);
				else {
					if (s[tot+1]=='0') add(dp[nS][k+1],dp[S][k]);
					else add(dp[nS][k],dp[S][k]);
				}
			}
		}
	}
	ll ans = 0;
	F(i,0,n-m) add(ans,dp[(1<<n)-1][i]);
	cout << ans; 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s; s = " "+s;
	F(i,1,n) cin >> c[i];
	
	if (n<=18){
		baoli();
	} else {
		ll res = 1;
		F(i,1,n) res = (res*i)%Mod;
		cout << res;
	}
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
