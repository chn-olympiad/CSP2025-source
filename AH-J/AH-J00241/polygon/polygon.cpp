#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
const int mod=998244353;
int a[5005];
void dfs(int now,int sum,int mx){
	if(now>n){
		if(sum>mx*2)ans++,ans%=mod;
		return;
	}
	dfs(now+1,sum+a[now],max(mx,a[now]));
	dfs(now+1,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<0;
	}
	else dfs(1,0,0),cout<<ans;
	return 0;
}
