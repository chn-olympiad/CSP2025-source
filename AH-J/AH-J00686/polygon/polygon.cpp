#include<bits/stdc++.h>
using namespace std;
int const mod=998244353;
int n,a[5010],dp[5010];
long long ans;
void dfs(int x,int sum,int maxn,int cnt){
	if(x>n){
		if(sum>maxn*2&&cnt>=3) ans++;
		ans%=mod;
		return;
	}
	dfs(x+1,sum+a[x],a[x],cnt+1);
	dfs(x+1,sum,maxn,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans%mod<<endl;
	return 0;
}
