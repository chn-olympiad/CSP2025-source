#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn][4],ans1,s[4],vis[maxn],ans,n,mem[maxn][4];
void dfs(int k){
	if(k>n){
		for(int i=1;i<=3;i++){
			if(s[i]>n/2){
				return;
			}
		}
		ans=max(ans,ans1);
	
		return;
	}
	if(vis[k]){
		return;
	}
	for(int i=1;i<=3;i++){
		if(s[i]>=n/2){
			continue;
		}
		s[i]++;
		vis[k]=1;
		ans1+=a[k][i];
		dfs(k+1);
		s[i]--;
		vis[k]=0;
		ans1-=a[k][i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
