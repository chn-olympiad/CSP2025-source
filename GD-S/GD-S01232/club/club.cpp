#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll n,t,a[N],b[N],c[N],ans;
void dfs(ll dep,ll i,ll j,ll res){
	if(dep>n)return ans=max(ans,res),void();
	if(i+1<=n/2)dfs(dep+1,i+1,j,res+a[dep]);
	if(j+1<=n/2)dfs(dep+1,i,j+1,res+b[dep]);
	if(dep-i-j+1<=n/2)dfs(dep+1,i,j,res+c[dep]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n,ans=0;
		for(ll i=1;i<=n;++i)cin>>a[i]>>b[i]>>c[i];
		dfs(0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

