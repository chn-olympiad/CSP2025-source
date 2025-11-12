#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
#define ll long long
ll n,le[5005],vis[5005],ans=0;
void dfs(ll x,ll p,ll len,ll maxx) {
	if(p>=3&&vis[x-1]==1&&len>2*maxx) ans++;
	if(x>n) return;
	vis[x]=1;
	dfs(x+1,p+1,len+le[x],max(le[x],maxx));
	vis[x]=0;
	dfs(x+1,p,len,maxx);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>le[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
