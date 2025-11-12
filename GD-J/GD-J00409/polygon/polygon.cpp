#include<iostream>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,a[5003],ans;
void dfs(int dep,int se,int sum,int mx){
	if(dep==n+1){
		if(se<3||sum<=2*mx)return;
		ans++;
		ans%=mod;
		return;
	}
	dfs(dep+1,se,sum,mx);
	dfs(dep+1,se+1,sum+a[dep],max(mx,a[dep]));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
