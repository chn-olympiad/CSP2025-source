#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[50002],ans;
void dfs(int j,int num,int maxx,int sum){
	if(num>=3&&sum>2*maxx) ans++;
	for(int i=j+1;i<=n;i++) dfs(i,num+1,max(maxx,a[i]),sum+a[i]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}