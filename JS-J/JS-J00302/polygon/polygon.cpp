#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,vis[5005];
map<double,int>mp;
void dfs(int deep,int sum,int maxn){
	if(deep>=3){
		double p=maxn/deep/sum;
		if(mp.find(p)==mp.end()){
			if(sum>2*maxn){
				mp[p]=1;
				ans++;
			}
		}
		if(deep==n)	return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)	continue;
		vis[i]=1;
		dfs(deep+1,sum+a[i],max(maxn,a[i]));
		vis[i]=0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
