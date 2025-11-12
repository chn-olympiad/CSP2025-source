#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,a[5005],ans,flag1=1;
void dfs(int d,int cnt,int sum,int mx){
	if(d==n+1){
		if(cnt>2&&sum>mx*2){ans++;ans%=998244353;}
		return;
	}
	dfs(d+1,cnt+1,sum+a[d],max(mx,a[d]));
	dfs(d+1,cnt,sum,mx);
}
int c(int n,int m){
	int res=1;
	for(int i=1;i<=n;i++){res=(res*(m-i+1)/i)%998244353;}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];flag1=(a[i]==1?1:0);}
	if(flag1){
		for(int i=3;i<=n;i++)ans=(ans+c(i,n))%998244353;
	}
	else dfs(1,0,0,0);
	cout<<ans;
	return 0;
}