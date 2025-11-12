#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e3+5;
#define mod 998244353
#define ll long long
int n,nn;
int a[maxn],cnt[maxn];
ll ans=0;
int use[maxn];
bool used[maxn],flag=1;
int maxs,num;
void dfs(int dep,int maxx,int sum){
	if(dep==nn+1){
		if(sum>2*maxx){
			ans=(ans+1)%mod;
			return ;
		}
	}
	for(int i=use[dep-1]+1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			use[dep]=i;
			dfs(dep+1,max(maxx,a[i]),sum+a[i]);
			used[i]=0;
			use[dep]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxs=max(maxs,a[i]);
		num+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(num>maxs*2) cout<<1;
		else cout<<0;
		return 0;
	}
	else if(maxs==1){
		ll t=1;
		for(int i=n;i>=n-3+1;i--) t=(t%mod*i%mod)%mod;
		cout<<t/6;
		return 0;
	}
	for(int i=3;i<=n;i++){
		memset(used,0,sizeof(used));
		memset(use,0,sizeof(use));
		nn=i;
		dfs(1,0,0);
	}
	cout<<ans%mod;
	return 0;
}