#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[5010],vis[5010],ans;
void dfs(ll id,ll sum,ll mx,ll num){
	if(id==n+1){
		if(num<3)return;
		if(sum<=2*mx)return;
		ans++;
		return;
	}
	vis[id]=true;
	dfs(id+1,sum+a[id],max(mx,a[id]),num+1);
	vis[id]=false;
	dfs(id+1,sum,mx,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(ll i=1;i<=n;i++)cin >> a[i];
	dfs(1,0,0,0);
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
