#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,a[N],g[N],ans,maxn,da;
void dfs(int u){
	if(u>n){
		ans=max(ans,maxn);
		maxn--;
		return;
	}for(int i=u+1;i<=n;++i){
		if(g[i]^g[u-1]==k){
			cout<<i<<' '<<u<<endl;
			maxn++;	
			dfs(i);
		}
	}dfs(u+1);
	maxn--;
	return;
}int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(!a[i])da++;
		g[i]=g[i-1]^a[i];
	}if(!k){
		cout<<da;
		return 0;
	}else if(k==1){
		cout<<n-da;
		return 0;		
	}dfs(1);
	cout<<ans;
	return 0;
}
