#include<bits/stdc++.h>
using namespace std;
long long ans=0,sum=0,quee[500003];
void dfs(long long dep,long long xorh,long long n,long long k){
	if(xorh==k){
		sum++,ans=max(ans,sum);
		if(quee[dep]!=-1)
			dfs(dep+1,quee[dep+1],n,k);
		sum--;
	}
	else{
		if(quee[dep]==-1) return;
		dfs(dep+1,xorh^quee[dep],n,k);
		dfs(dep+1,quee[dep+1],n,k);
	}
	
}
signed main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n,k,i;
	memset(quee,-1,sizeof(quee));
	cin>>n>>k;
	for(i=1;i<=n;i++)
		scanf("%lld",&quee[i]);
	dfs(1,quee[1],n,k);
	cout<<ans;
	return 0;
}