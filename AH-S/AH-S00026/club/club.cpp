#include<bits/stdc++.h>
using namespace std;
int sum1,sum2,sum3;
struct node{
	int a,b,c;
	int sum;
}clu[1000005];
int dp[205][105][105];
int n,ans;
long long sum=0;
bool cmp(node p,node q){
	return p.a>q.a;
}
int T;
void work1(){
	//It stands for I can get 55 score.
	ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&clu[i].a,&clu[i].b,&clu[i].c);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;(j<<1)<=n&&j<=i;j++){
			for(int k=0;(k<<1)<=n&&k<=i-j;k++){
				if(((i-j-k)<<1)>n)continue;
				int cnum=i-j-k;
				dp[j][k][cnum]=0;
				if(j)dp[j][k][cnum]=max(dp[j-1][k][cnum]+clu[i].a,dp[j][k][cnum]);
				if(k)dp[j][k][cnum]=max(dp[j][k-1][cnum]+clu[i].b,dp[j][k][cnum]);
				if(cnum)dp[j][k][cnum]=max(dp[j][k][cnum-1]+clu[i].c,dp[j][k][cnum]);
				ans=max(ans,dp[j][k][cnum]);
			}
		}
	}
	printf("%d\n",ans);
}
void work2(){
	//It stands for I can get other 5 score.
	sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&clu[i].a,&clu[i].b,&clu[i].c);
	}
	sort(clu+1,clu+n+1,cmp);
	for(int i=1;(i<<1)<=n;i++){
		sum+=(clu[i].a);
	}
	printf("%lld\n",sum);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n<=200)work1();
		else work2();
	}
	return 0;
}
