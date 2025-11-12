#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005],n,ans;
void dfs(int sum,int cnt,int mx,int s){
	if(cnt>=3&&sum>mx*2){
		ans++;
		ans%=998244353;
	}
	if(cnt+n-s<3)return ;
	for(int i=s+1;i<=n;i++)dfs(sum+a[i],cnt+1,max(mx,a[i]),i);
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
