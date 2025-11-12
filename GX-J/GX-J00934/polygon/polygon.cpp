#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
ll n,a[500010],ans,cnt;
bool vis[500010];
ll c(ll n,ll m){
	ll ans=1;
	for(int i=n-m+1,j=1;i<=n,j<=m;i++,j++){
		ans=(ans*i/j)%MOD;
		cout<<ans<<endl;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n;
	bool all1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		all1&=(a[i]==1);
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[3]<a[1]+a[2])ans=1;
		else ans=0;
	}else if(all1){
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
		}
	}else{
		
	}
	cout<<ans;
	return 0;
}
