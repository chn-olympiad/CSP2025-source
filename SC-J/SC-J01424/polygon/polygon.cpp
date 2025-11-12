#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n;
int ans;
int a[5005],qzh[5005];
int c[5005];
void dfs(int k,int sum,int ws){
	if(sum+qzh[ws-1]-qzh[k-1]<=a[ws]) return;
	if(k==ws){
		if(sum>a[ws]) ans=(ans+1)%MOD;
		return;
	}
	dfs(k+1,sum,ws);
	dfs(k+1,sum+a[k],ws);
	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		qzh[i]=qzh[i-1]+a[i];
	}
	if(a[n]==1){
		c[0]=1;
		int ans0=1;
		for(int i=1;i<=n/2;++i){
			c[i]=(c[i-1]*(n-i+1)/i)%MOD;
			ans0=(ans0+c[i])%MOD;
		}
		if(n%2==0){
			cout<<(ans0+ans0-c[1]-c[2]-c[0]-c[n/2])%MOD;
		}else{
			cout<<(ans0+ans0-c[1]-c[2]-c[0])%MOD;
		}
		return 0;
	}
	for(int i=3;i<=n;++i){
		dfs(1,0,i);
	}
	cout<<ans;
	return 0;
}