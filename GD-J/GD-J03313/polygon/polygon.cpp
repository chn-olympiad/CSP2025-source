#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[5005],ans,vis[5005];
void dfs(int x,int mx,int len,bool fl) {
	if(x==n+1) {
		return;
	}
	if(len>2*mx&&fl) {
		ans++;
	}
	dfs(x+1,((a[x+1]>mx)?a[x+1]:mx),len+a[x+1],1);
	dfs(x+1,mx,len,0);
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
