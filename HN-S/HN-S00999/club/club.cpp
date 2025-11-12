#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+50;
ll t,n;
ll a[maxn],b[maxn],c[maxn];
ll ans;
ll dfs(ll x,ll s1,ll s2,ll s3,ll sum){
	if(s1>n/2||s2>n/2||s3>n/2)return 0;
	if(x>n){
		ans=max(sum,ans);
		return 0;
	}
	dfs(x+1,s1+1,s2,s3,sum+a[x]);
	dfs(x+1,s1,s2+1,s3,sum+b[x]);
	dfs(x+1,s1,s2,s3+1,sum+c[x]);
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
