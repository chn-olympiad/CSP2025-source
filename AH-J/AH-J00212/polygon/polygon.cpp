#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],sum[N],ans;
void dfs(int now,int sum,int ge,int mx){
	if(n-now+1+ge<3)return;
	if(now==n+1){
		if(ge>=3&&sum>mx*2)ans++;
		ans%=mod;
		return;
	}
	dfs(now+1,sum+a[now],ge+1,a[now]);
	dfs(now+1,sum,ge,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
