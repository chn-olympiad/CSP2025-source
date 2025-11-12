#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10;
const ll MOD=998244353;
int n;
int a[N],sum[N];
ll ans=0;
ll p2[N];
bool cmp(int p,int q){
	return p>q;
}
ll qpow(ll a,ll b){
	int res=1;
	while(b){
		if(b%2) res=(res*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return res;
}
void dfs(int stid,int nid,int s){
	if(s+sum[nid]<=2*a[stid]) return;
	//cout<<a[stid]<<" "<<a[nid]<<" "<<s<<" "<<ans<<"\n";
	if(s>2*a[stid]){
		ans=(ans+p2[n-nid])%MOD;
		return;
	}
	for(int i=nid+1;i<=n;i++) dfs(stid,i,s+a[i]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	for(int i=0;i<=5000;i++) p2[i]=qpow(2,i);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	sum[n+1]=0;
	for(int i=n;i>=1;i--) sum[i]=sum[i+1]+a[i];
	for(int i=1;i<=n;i++) dfs(i,i,a[i]);
	cout<<ans;
	return 0;
}