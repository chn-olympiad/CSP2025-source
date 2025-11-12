#include<bits/stdc++.h>
#define ll  long long
using namespace std;
ll l[5015],n,mx=-1e7,ans;bool v[5015];
void dfs(ll d,ll mx,ll i){
	if(i>n)return;
	if(d>=3){
		ll sum=0;
		for(int i=1;i<=n;i++)if(v[i]==true)sum+=l[i];
		if(sum>mx)
			ans++;
	}
	v[i]=true;
	dfs(d+1,max(mx,l[i]),i+1);
	v[i]=false;
	dfs(d,mx,i+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>l[i];
	dfs(0,-1e7,1);
	cout<<ans%998244353<<" \n";
	return 0;
}
