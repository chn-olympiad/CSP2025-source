//30'baoli
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int n;
int a[5010];
int an[5010];
long long ans;
const long long mod = 998244353;
void dfs(int dep,int cnt,int sum,int maxx){
//	printf("%d %d %d\n",dep,cnt,sum);
	if (dep == n+1){
		if (cnt >= 3 && sum > maxx * 2){
//			rep(i,1,cnt) printf("%d ",an[i]);
//			printf("\n");
			ans++;
			ans %= mod;
		}
		return;
	}
	if (n - dep + 1 + cnt < 3) return;
//	if (cnt < 2) an[cnt+1] = a[dep],dfs(dep+1,cnt+1,sum+a[dep]),an[cnt+1] = 0;
//	if (cnt >= 2 && sum + a[dep] > a[dep] * 2) an[cnt+1] = a[dep],dfs(dep+1,cnt+1,sum+a[dep]),a[cnt+1] = 0;
	dfs(dep+1,cnt+1,sum+a[dep],a[dep]);
	dfs(dep+1,cnt,sum,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	rep(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout << ans;
	return 0;
}

