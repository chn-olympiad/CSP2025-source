#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e2 + 24;
const int mod = 998244353;
int n,ans;
int a[maxn],s[maxn];
int dfs(int x,int sum,int val,int n,int cnt){
	if(val - sum >= s[x]){
		return 0;
	}
	if(cnt == n){
		return 1;
	}
	int ans = 0;
	if(sum > val){
		ans++;
	}
	for(int i = x - 1;i;i--){
		ans = (ans + dfs(i,sum + a[i],val,n,cnt + 1)) % mod;
	}
	return ans;
} 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
	} 
	for(int i = 3;i <= n;i++){
		if(s[i - 1] <= a[i]){
			continue;
		}
		ans = (ans + dfs(i,0,a[i],i,0)) % mod;
	}
	cout << ans;
	return 0;
}
