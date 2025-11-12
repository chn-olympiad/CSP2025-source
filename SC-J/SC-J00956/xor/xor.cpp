#include<bits/stdc++.h>
using namespace std;
vector<int> f[500010];
int n,k,a,b[500010],ans,vis[500010];
void dfs(int l,int num){
	ans=max(ans,num);
	if(l>n)return;
	for(auto e:f[k^b[l-1]]){
		if(e<l)continue;
		if(vis[e]<num+1){
			vis[e]=num+1;
			dfs(e+1,num+1);
		}
	}
	for(int i=l+1;i<=n;i++){
		if(vis[i]==0){
			dfs(i,num);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		b[i]=b[i-1]^a;
		f[b[i]].push_back(i);
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
	
} 