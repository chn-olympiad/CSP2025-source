#include<bits/stdc++.h>
using namespace std;
const int ri=5005,mo=998244353;
int n,vis[ri],f[ri][ri],a[ri],ans;
void dfs(int u,int cnt,int mx,int sum,bool ch){
	//cout<<u<<" "<<cnt<<" "<<mx<<" "<<sum<<endl;
	if(u==n+1){
		if(sum>2*mx&&cnt>2&&ch){
			ans=(ans+1)%mo;
		}
		return;
	}
	if(sum>2*mx&&cnt>2&&ch){
		ans=(ans+1)%mo;
	}
	dfs(u+1,cnt,mx,sum,0);
	if(!vis[u]){
		vis[u]=1;
		dfs(u+1,cnt+1,max(mx,a[u]),sum+a[u],1);
		vis[u]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
//	sort(a+1,a+n+1);
	dfs(1,0,0,0,0);
	printf("%lld\n",ans%mo);
	return 0;
} 
