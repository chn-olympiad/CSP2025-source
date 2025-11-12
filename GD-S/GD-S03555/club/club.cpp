#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,dp[201][201][201],ans,maxb,maxc;
struct node{
	int a,b,c;
}member[100001];
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.a-x.b>y.a-y.b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		maxb=maxc=0;
		memset(dp,0,sizeof dp);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&member[i].a,&member[i].b,&member[i].c),maxb=max(maxb,member[i].b),maxc=max(maxc,member[i].c);
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+member[i].a);
						if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+member[i].b);
						if(i-j-k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+member[i].c);
					}
				}
			}
			ans=0;
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(n-j-k<=n/2)ans=max(ans,dp[n][j][k]);
				}
			}			
		}else if(maxb==0 && maxc==0){
			sort(member+1,member+1+n,cmp1);
			ans=0;
			for(int i=1;i<=n/2;i++)ans+=member[i].a;
		}else if(maxc==0){
			sort(member+1,member+1+n,cmp2);
			ans=0;
			for(int i=1;i<=n/2;i++)ans+=member[i].a;
			for(int i=n/2+1;i<=n;i++)ans+=member[i].b;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
