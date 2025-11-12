#include<bits/stdc++.h>
using namespace std;
int t,n,vis[100005];
long long tong[10],ans,in[100005][10];
struct P{
	long long a;
	int id;
}q[100005];
bool cmp(P x,P y){
	return x.a>y.a;
}
void dfs(int depth,long long atp){
	if(depth==n+1){
		ans=max(atp,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		for(int j=1;j<=3;j++){
			if(tong[j]<n/2){
				tong[j]++;
				vis[i]=1;
				dfs(depth+1,atp+in[i][j]);
				tong[j]--;
				vis[i]=0;
			}	
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int p=0;
		scanf("%d",&n);
		ans=0;
		memset(vis,0,sizeof(vis));
		memset(tong,0,sizeof(tong));
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&in[i][1],&in[i][2],&in[i][3]);	
			q[i].a=in[i][1];
			q[i].id=i;
			if(in[i][2]!=0||in[i][3]!=0){
				p=1;
			}
		}	
		if(p==0){
			sort(q+1,q+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=q[i].a;
			}
			printf("%lld\n",ans);
		}
		else{
			dfs(1,0);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
