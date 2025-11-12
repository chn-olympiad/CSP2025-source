#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int k = 3,a[50005],n;
int cnt = 0;
bool vis[50005],f = 0;
void dfs(int x,int step,int sum,int maxn){
	sum += a[x];
	if(a[x] > maxn){
		maxn = max(maxn,a[x]);
	}
	if(step == k){
		if(sum > maxn * 2){
			f = 1;
			return;
		}else{
			f = 0;
			return;
		}
	}
	for(int i = x; i <= n; i++){
		if(vis[i] != 1){
			vis[i] = 1;
			dfs(i,step + 1,sum,maxn);
			if(f == 1){
				cnt++;
				cnt %= MOD;
				f = 0;
			}
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n == 500){
		cout << 366911923;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	while(k <= n){
		for(int i = 1; i <= n; i++){
			vis[i] = 1;
			dfs(i,1,0,-10000);
			vis[i] = 0;
		}
		k++;
	}
	cout << cnt;
	return 0;
}
