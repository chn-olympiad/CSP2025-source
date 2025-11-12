#include<bits/stdc++.h>
using namespace std;
const int N=5005,MOD=998244353;
int n,a[N],mx,ans;
void dfs(int step,int sum,int mx){
	if(step>n){
		if(sum>2*mx)ans=(ans+1)%MOD;
		mx=0;
		return;
	}
	dfs(step+1,sum+a[step],max(mx,a[step]));
	dfs(step+1,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

