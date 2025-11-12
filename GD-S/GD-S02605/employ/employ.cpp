#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510;
const int MOD = 998244353;
int n,m,a[N],c[N],fac[N];
int p[N],ans,st[N],top,f[N];
bool vis[N];
void dfs(int dep){
	if(dep == n){
		int tot = 0,sum = 0;
		for(int i = 1;i<=n;i++){
			if(a[i] == 0){
				tot++;
				continue;
			}
			else if(tot >= c[p[i]]){
				tot++;
				continue;
			}
			else sum++;
		}
		if(sum >= m) ans = (ans + 1) % MOD;
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			vis[i] = true;
			p[dep+1] = i;
			dfs(dep + 1);
			vis[i] = false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	fac[0] = 1;
	for(int i = 1;i<=n;i++)
		fac[i] = fac[i-1] * i % MOD;
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		char c; cin>>c;
		a[i] = c - '0';
		cnt += a[i];
		if(a[i] == 1) st[++top] = i;
	}
	for(int i = 1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1);
	
	if(n <= 10) dfs(0);
	else{
		for(int i = 0;i<(1<<cnt);i++){
			int res = 1;
			for(int j = 0;j<cnt;j++){
				f[j + 1] = f[j] + ((i >> j) & 1);
			}
			int tot = 0;
			for(int j = cnt - 1;j>=0;j--){
				if(((i >> j) & 1) == 0) continue;
				int pos = st[j + 1] - f[j];
				int p = lower_bound(c+1,c+n+1,pos) - c;
				int migi = tot;
				tot++;
				int hv = (n - p + 1) - migi;
			//	cout<<j<<' '<<hv<<endl;
				res = (res * hv) % MOD;
			}
			res = res * fac[n - tot] % MOD;
			if(tot >= m) ans = (ans + res) % MOD;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
