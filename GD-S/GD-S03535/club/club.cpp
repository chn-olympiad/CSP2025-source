#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t,n,a1[100005],a2[100005],a3[100005],ans=0,A=1,dp[100005],c[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		int cg=(n/2);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			if(a2[i]!=0||a3[i]!=0) A=0;
		}
		if(A==1){
			sort(a1+1,a1+n+1);
			for(int i=n;i>cg;i--){
				ans+=a1[i];
			}
			printf("%d\n",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				int ma=max(max(a1[i],a2[i]),a3[i]);
				dp[i]+=ma;
				if(ma==a1[i]) c[1]++;
				else if(ma==a2[i]) c[2]++;
				else c[3]++;
				if(c[1]>cg){
					c[1]--;
					dp[i]-=ma;
					int lll=(a1[i]+a2[i]+a3[i])-max(a1[i],max(a2[i],a3[i]))-min(a1[i],min(a2[i],a3[i]));
					dp[i]+=lll;
					if(lll==c[2]){
						c[2]++;
					}
					if(lll==c[3]){
						c[3]++;
					}
				}
				if(c[2]>cg){
					c[2]--;
					dp[i]-=ma;
					int lll=(a1[i]+a2[i]+a3[i])-max(a1[i],max(a2[i],a3[i]))-min(a1[i],min(a2[i],a3[i]));
					dp[i]+=lll;
					if(lll==c[1]){
						c[1]++;
					}
					if(lll==c[3]){
						c[3]++;
					}
				}	
				if(c[3]>cg){
					c[3]--;
					dp[i]-=ma;
					int lll=(a1[i]+a2[i]+a3[i])-max(a1[i],max(a2[i],a3[i]))-min(a1[i],min(a2[i],a3[i]));
					dp[i]+=lll;
					if(lll==c[2]){
						c[2]++;
					}
					if(lll==c[1]){
						c[1]++;
					}
				}
			}
			printf("%d\n",dp[n]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
