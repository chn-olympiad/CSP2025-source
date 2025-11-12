#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,a[114514],res,vis[114514];
void dfs(int x,int y,int sum,int num,int d){
	if(x > 2) if(sum > num) res++;
	if(x > y) return;
	for(int i=d+1;i<=y;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(x+1,y,sum+a[i],num,i);
			vis[i] = 0;
		}
	}
}
int f(int x){
	int r = 1;
	for(int i=1;i<=x;i++) r *= i;
	return r;
}
int c(int x,int y){
	return f(x)/f(y)/f(x-y);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	if(a[n] == a[1]){
		for(int i=3;i<=n;i++){
			res += c(n,i);
		}
		cout << res%mod;
		return 0;
	}
	for(int i=3;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(1,i-1,0,a[i],0);
	}
	cout << res%mod;
	return 0;
}
