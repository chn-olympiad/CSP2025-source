#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5006];
void dfs(int x,int sum,int mx){
	if(x==n+1){
		if(sum>mx*2) ans++;
		ans%=998244353;
		return;
	}
	dfs(x+1,sum,mx);
	dfs(x+1,sum+a[x],max(mx,a[x]));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}