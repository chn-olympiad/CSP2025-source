#include<bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int n,maxn,a[10005];
long long ans = 0;
bool vis[10005],f = 1;
map<vector<int>,int> mp;
void dfs(int k){
	if(k >= 3){
		int res = 0,maxn = 0;
		vector<int> num;
		for(int i = 1;i <= n;i++){
			if(vis[i]){
				num.push_back(i);
				res += a[i];
				maxn = max(maxn,a[i]);
			}
		}
		if(!mp.count(num)){
			if(res > 2 * maxn){
				mp[num] = ans;
				ans = (ans + 1) % MOD;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(k + 1);
			vis[i] = 0;
		}
	}
}
long long fac(int n){
	long long res = 1;
	for(int i = 1;i <= n;i++){
		res = (res * i) % MOD;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(a[i] != 1) f = 0;
	}
	sort(a + 1,a + n + 1);
	if(f){
		for(int i = 3;i <= n;i++){
			long long st1 = fac(n) % MOD,st2 = fac(n - i) % MOD,st3 = fac(i) % MOD;
			ans = (ans + (st1 / (st2 * st3))) % MOD;
		}
		printf("%lld",ans);
	}else{
		for(int i = 1;i <= n;i++){
			vis[i] = 1;
			dfs(1);
			vis[i] = 0;
		}
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
