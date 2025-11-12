# include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,m,r,summ,l,k,ans;
//const int xzl=6666666;
const int yyzmm=-10086;
int a[500000];
long long dp[500005];
void dfs(long long x,long long y,long long z,int q){
	if(x==n+1){
		if(z>y*2&&q>=3){
			ans++;
			ans%=MOD;
		}
		return;
	}
	dfs(x+1,y,z,q);
	dfs(x+1,a[x],z+a[x],q+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<500) dfs(1,0,0,0);
	else{
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=MOD;
		}
		ans+=MOD;
		ans--;
		ans-=n;
		ans-=n*(n-1);
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}
