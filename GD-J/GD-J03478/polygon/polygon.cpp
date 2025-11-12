#include<bits/stdc++.h>
using namespace std;
#defien ll long long
ll n,stk[10001],bstk[10001],vis[10001],bans=0;
bool cortect(int k){
	ll ans=0,maxx=-1;
	for(int i=1;i<=k;i++){
		maxx=max(maxx,stk[bstk[i]]);
		ans+=stk[bstk[i]];
	}
	return ans>maxx*2;
}
void dfs(int p,int k){
	if(p==k+1){
		if(cortect(k)){
			bans++;
			bans%=998244353;
		}
		
	}
	for(int i=max(bstk[p-1],1);i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		bstk[p]=i;
		dfs(p+1,k);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stk[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,i);
	}
	cout<<bans;
}
// oh no tle
// eaaaaaaa>O<
// ok  change t3

// this only 50pts
// ohnoooooo

// empty
