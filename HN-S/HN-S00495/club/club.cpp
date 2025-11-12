#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010
int T,n,a[MAXN][4],b[4][MAXN],ans,tot[3];
bool flag;
void dfs(int now,int sum){
	if(now==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	    if(tot[i]<n/2){
	    	tot[i]++;
	    	dfs(now+1,sum+b[i][now]);
	    	tot[i]--;
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ans=0;memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=3;j++){
		    	scanf("%d",&b[j][i]);
		    	if(j!=1&&b[j][i])flag=1;
			}
		if(flag){
			dfs(1,0);
			printf("%d\n",ans); 
			continue;
		}
        sort(b[1]+1,b[1]+n+1,greater<int>());
		for(int i=1;i<=n/2;i++)
		    ans+=b[1][i];
		printf("%d\n",ans);
	}
	return 0;
}
