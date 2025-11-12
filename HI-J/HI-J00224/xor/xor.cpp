#include<bits/stdc++.h>
using namespace std;
int n,k,a[500100],s[500100],to[500100],ans;
void dfs(int stp,int cnt){
	if(stp==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(to[stp]!=0)dfs(to[stp],cnt+1);
	dfs(stp+1,cnt);
}
//abs(a)<abs(o)
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=i;j<=n;j++){
			tmp=tmp^a[j];
			if(tmp==k){
				to[i]=j+1;
				break;
			}
		}
	}
//	for(int i=1;i<=n;i++)printf("%d ",to[i]);
	dfs(1,0);
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

