#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],ans,jc[N];
void dfs(int st,int sum,int mx,int num){
	if(st>n){
		if(sum>mx*2&&num>=3)ans++;
		return;
	}
	dfs(st+1,sum+a[st],max(a[st],mx),num+1);
	dfs(st+1,sum,mx,num);
}
int fp(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	ans++;
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;
	for(int i=3;i<=n;++i)ans=ans+jc[n]*fp(n-i,mod-2)%mod*fp(i,mod-2)%mod;
	cout<<ans;
	return 0;
}
/*
5
2 2 3 8 10
5
1 2 3 4 5
*/