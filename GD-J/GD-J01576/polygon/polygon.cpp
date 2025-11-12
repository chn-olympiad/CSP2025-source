#include <bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010];
int n;
struct node{
	int maxn,sum,bian;
}dp[100010];
long long ans=0;
void solve(){
	sort(a+1,a+4);
	if(a[1]+a[2]>a[3]){
		cout << 1;
	}
	else{
		cout << 0;
	}
}
void dfs(int x,int maxn,int sum,int o){
	if(x==n+1){
		if(o<3||sum<=maxn*2){
			return ;
		}
		ans++;
		ans%=998244353;
		return ;
	}
	dfs(x+1,maxn,sum,o);
	int y=max(maxn,a[x]);
	dfs(x+1,y,sum+a[x],o+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	if(n<3){
		cout << 0;
	}
	else if(n==3){
		solve();
	}
	else {
		dfs(1,0,0,0);
		cout << ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
