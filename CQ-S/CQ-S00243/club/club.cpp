#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[100000+10][3+10];
int s=0,mx,dp[200+10][100+10][100+10];
bool flag=1;
struct node{
	int val;
	bool operator<(const node &next)const{
		return val>next.val;
	}
};
priority_queue<node>pq;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),m=n/2,mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
			if(a[i][2]>0||a[i][3]>0)flag=0;
			else{
				if(pq.size()<n/2)s+=a[i][1],pq.push({a[i][1]});
				else if(pq.top().val<a[i][1])s+=a[i][1]-pq.top().val,pq.pop(),pq.push({a[i][1]});
			}
		}
		if(flag){
			printf("%d\n",s);
			continue;
		}
		for(int i=1;i<=n;i++)for(int j=0;j<=m;j++)for(int k=0;k<=m;k++){
			dp[i][j][k]=0;
			if(0<=i-j-k&&i-j-k<=m){
				if(j!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
				if(k!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
				if(i-j-k!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				mx=max(mx,dp[i][j][k]); 
			}
		}
		printf("%d\n",mx);
	}
	return 0;
}
