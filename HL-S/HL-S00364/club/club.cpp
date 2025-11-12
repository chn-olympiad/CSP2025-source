#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a1[100010],a2[100010],a3[100010];
int ans;
int dp[210][210][210];
struct node{
	int x,y;
}a[100010];
bool cmp(node m,node n){
	return m.x-n.x>m.y-n.y;
}
void dfs(int idx,int cnt1,int cnt2,int cnt3,int sum){
	if(idx>n){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<(n>>1)){
		dfs(idx+1,cnt1+1,cnt2,cnt3,sum+a1[idx]);
	}
	if(cnt2<(n>>1)){
		dfs(idx+1,cnt1,cnt2+1,cnt3,sum+a2[idx]);
	}
	if(cnt3<(n>>1)){
		dfs(idx+1,cnt1,cnt2,cnt3+1,sum+a3[idx]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool typeA=true,typeB=true;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			if(a2[i]||a3[i]){
				typeA=false;
			}
			if(a3[i]){
				typeB=false;
			}
		}
		if(n<=10){
			ans=0;
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
		}else if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=i;j++){
					for(int k=0;k<=i-j;k++){
						dp[i][j][k]=0;
						if(j){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a1[i]);
						}
						if(k){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a2[i]);
						}
						if(i-j-k){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a3[i]);
						}
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n-i;j++){
					if(i<=(n>>1)&&j<=(n>>1)&&n-i-j<=(n>>1)){
						ans=max(ans,dp[n][i][j]);
					}
				}
			}
			printf("%d\n",ans);
		}else if(typeA){
			sort(a1+1,a1+n+1);
			int ans=0;
			for(int i=(n>>1)+1;i<=n;i++){
				ans+=a1[i];
			}
			printf("%d\n",ans);
		}else if(typeB){
			for(int i=1;i<=n;i++){
				a[i].x=a1[i],a[i].y=a2[i];
			}
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=(n>>1);i++){
				ans+=a[i].x;
			}
			for(int i=(n>>1)+1;i<=n;i++){
				ans+=a[i].y;
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}