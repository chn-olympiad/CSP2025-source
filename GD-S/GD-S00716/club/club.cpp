#include<bits/stdc++.h>
using namespace std;
struct node{
	int a1,a2,a3;
}s[100007];
int n;
int T;
int a[100007][5];
int dp[100007][5];
bool cmp(node x,node y){
	return x.a1>y.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		bool f1=1,f2=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			s[i].a1=a[i][1];
			s[i].a2=a[i][2];
			s[i].a3=a[i][3];
			if(a[i][2]!=0||a[i][3]!=0){
				f1=0;
			}
			if(a[i][3]!=0){
				f2=0;
			}
		}
		if(f1){
			sort(s+1,s+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum=sum+s[i].a1;
			}
			printf("%d",sum);
		}
		else if(f2){
			for(int i=1;i<=n;i++){
				int mx=max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][3]);
				dp[i][1]=mx+a[i][1];
				dp[i][2]=mx+a[i][2];
				dp[i][3]=mx+a[i][3];
			}
			printf("%d\n",max(max(dp[n][1],dp[n][2]),dp[n][3]));
		}
		else{
			for(int i=1;i<=n;i++){
				int mx=max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][3]);
				dp[i][1]=mx+a[i][1];
				dp[i][2]=mx+a[i][2];
				dp[i][3]=mx+a[i][3];
			}
			printf("%d\n",max(max(dp[n][1],dp[n][2]),dp[n][3]));
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
