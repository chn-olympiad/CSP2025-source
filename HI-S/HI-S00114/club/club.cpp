#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
struct rec{int x,y,z;}a[100100];
void dfs(int stp,int sum,int ca,int cb,int cc){
	if(stp==n+1){
		ans=max(ans,sum);
		return;
	}
	if(ca<(n>>1))dfs(stp+1,sum+a[stp].x,ca+1,cb,cc);
	if(cb<(n>>1))dfs(stp+1,sum+a[stp].y,ca,cb+1,cc);
	if(cc<(n>>1))dfs(stp+1,sum+a[stp].z,ca,cb,cc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
		
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
		ans=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

