#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[588888];
int pre[588888];
int g[588888];
int m[588888];
void dfs(int x,int cnt){
	if(x==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(cnt<=m[x]) return;
	m[x]=cnt;
	if(g[x]!=0) dfs(g[x]+1,cnt+1);
	dfs(x+1,cnt);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=(pre[i-1]^a[i]);
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++){
		if((pre[i-1]^pre[j])==k){
			g[i]=j;
			break;
		}
	}
	for(int i=1;i<=n;i++) m[i]=-1;
	dfs(1,0);
	cout<<ans;
	return 0;
}
