#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
#define mod 998244353
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,a[5005],ans,maxn,sm[5005];
void dfs(int k,int maxx,int sum){
	if(k==n+1){
		if(sum>maxx*2) ans++;
		return;
	}
	dfs(k+1,maxx,sum);
	dfs(k+1,max(maxx,a[k]),sum+a[k]);
	return;
}
signed main(){
	IOS
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(a[i],maxn);
	if(n<=2) cout<<0<<endl;
	else if(n==3){
		if(a[1]+a[2]+a[3]>2*(max(a[1],max(a[2],a[3])))) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else if(n<=25){
		dfs(1,0,0);
		cout<<ans%mod<<endl;
	}
	else if(maxn==1){
		sm[0]=1;
		for(int i=1;i<=n;i++) sm[i]=(sm[i-1]*i)%mod;
		for(int i=3;i<=n;i++) ans+=(sm[i]/sm[i-3])%mod;
		cout<<ans<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
