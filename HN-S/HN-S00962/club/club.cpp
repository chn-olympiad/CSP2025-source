#include<bits/stdc++.h>
using namespace std;
struct str{
	int a1,a2,a3;
}s[101010];
int T;
int n,s1,s2,s3;
int dp[101010][4],dp1[101010][4][4];
bool cmp1(str a,str b){
	if(a.a1==b.a1){
		if(a.a2==b.a2){
			return a.a3>b.a3;
		}
		else return a.a2>b.a2;
	}
	else return a.a1>b.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a1,&s[i].a2,&s[i].a3);
			if(s[i].a2!=0)s2=1;
			if(s[i].a3!=0)s3=1;
			if(s[i].a1!=0)s1=1;
		}
		sort(s+1,s+n+1,cmp1);
		if(s2==0&&s3==0){
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=s[i].a1;
			}
			printf("%d\n",ans);
			continue;
		}
		if(s3==0&&s2!=0&&s1!=0){
			for(int i=1;i<=n;i++){
				int t1=(dp1[i-1][1][1]<(n/2)),t2=(dp1[i-1][2][1]<(n/2));
				dp[i][1]=max(dp[i-1][1]*t1,dp[i-1][2]*t2)+s[i].a1;
				if(dp[i][1]==dp[i-1][1]+s[i].a1){
					dp1[i][1][1]=dp1[i-1][1][1]+1;
					dp1[i][1][2]=dp1[i-1][1][2];
				}
				else if(dp[i][1]==dp[i-1][2]+s[i].a1){
					dp1[i][1][1]=dp1[i-1][2][1]+1;
					dp1[i][1][2]=dp1[i-1][2][2];
				}
				t1=(dp1[i-1][1][2]<(n/2));
				t2=(dp1[i-1][2][2]<(n/2));
				dp[i][2]=max(dp[i-1][1]*t1,dp[i-1][2]*t2)+s[i].a2;
				if(dp[i][2]==dp[i-1][1]+s[i].a2){
					dp1[i][2][1]=dp1[i-1][1][1];
					dp1[i][2][2]=dp1[i-1][1][2]+1;
				}
				else if(dp[i][2]==dp[i-1][2]+s[i].a2){
					dp1[i][2][1]=dp1[i-1][2][1];
					dp1[i][2][2]=dp1[i-1][2][2]+1;
				}
			}
			printf("%d\n",max(dp[n][1],dp[n][2]));
			continue;
		}
		for(int i=1;i<=n;i++){
			int t1=(dp1[i-1][1][1]<(n/2)),t2=(dp1[i-1][2][1]<(n/2)),t3=(dp1[i-1][3][1]<(n/2));
			dp[i][1]=max(dp[i-1][1]*t1,max(dp[i-1][2]*t2,dp[i-1][3]*t3))+s[i].a1;
			if(dp[i][1]==dp[i-1][1]+s[i].a1){
				dp1[i][1][1]=dp1[i-1][1][1]+1;
				dp1[i][1][2]=dp1[i-1][1][2];
				dp1[i][1][3]=dp1[i-1][1][3];
			}
			else if(dp[i][1]==dp[i-1][2]+s[i].a1){
				dp1[i][1][1]=dp1[i-1][2][1]+1;
				dp1[i][1][2]=dp1[i-1][2][2];
				dp1[i][1][3]=dp1[i-1][2][3];
			}
			else if(dp[i][1]==dp[i-1][3]+s[i].a1){
				dp1[i][1][1]=dp1[i-1][3][1]+1;
				dp1[i][1][2]=dp1[i-1][3][2];
				dp1[i][1][3]=dp1[i-1][3][3];
			}
			t1=(dp1[i-1][1][2]<(n/2));
			t2=(dp1[i-1][2][2]<(n/2));
			t3=(dp1[i-1][3][2]<(n/2));
			dp[i][2]=max(dp[i-1][1]*t1,max(dp[i-1][2]*t2,dp[i-1][3]*t3))+s[i].a2;
			if(dp[i][2]==dp[i-1][1]+s[i].a2){
				dp1[i][2][1]=dp1[i-1][1][1];
				dp1[i][2][2]=dp1[i-1][1][2]+1;
				dp1[i][2][3]=dp1[i-1][1][3];
			}
			else if(dp[i][2]==dp[i-1][2]+s[i].a2){
				dp1[i][2][1]=dp1[i-1][2][1];
				dp1[i][2][2]=dp1[i-1][2][2]+1;
				dp1[i][2][3]=dp1[i-1][2][3];
			}
			else if(dp[i][2]==dp[i-1][3]+s[i].a2){
				dp1[i][2][1]=dp1[i-1][3][1];
				dp1[i][2][2]=dp1[i-1][3][2]+1;
				dp1[i][2][3]=dp1[i-1][3][3];
			}
			t1=(dp1[i-1][1][3]<(n/2));
			t2=(dp1[i-1][2][3]<(n/2));
			t3=(dp1[i-1][3][3]<(n/2));
			dp[i][3]=max(dp[i-1][1]*t1,max(dp[i-1][2]*t2,dp[i-1][3]*t3))+s[i].a3;
			if(dp[i][3]==dp[i-1][1]+s[i].a3){
				dp1[i][3][1]=dp1[i-1][1][1];
				dp1[i][3][2]=dp1[i-1][1][2];
				dp1[i][3][3]=dp1[i-1][1][3]+1;
			}
			else if(dp[i][3]==dp[i-1][2]+s[i].a3){
				dp1[i][3][1]=dp1[i-1][2][1];
				dp1[i][3][2]=dp1[i-1][2][2];
				dp1[i][3][3]=dp1[i-1][2][3]+1;
			}
			else if(dp[i][3]==dp[i-1][3]+s[i].a3){
				dp1[i][3][1]=dp1[i-1][3][1];
				dp1[i][3][2]=dp1[i-1][3][2];
				dp1[i][3][3]=dp1[i-1][3][3]+1;
			}
		}
		printf("%d\n",max(dp[n][1],max(dp[n][2],dp[n][3])));
	}
	return 0;
}
