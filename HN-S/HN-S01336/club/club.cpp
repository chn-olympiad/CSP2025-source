#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct node1{
	int a,b,c,ma;
}m[N];
bool cmp(node1 a,node1 b){
	return a.ma>b.ma;
}
struct node2{
	int s,s1,s2,s3;
}dp[N][4];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			m[i].ma=max(m[i].a,max(m[i].b,m[i].c));
		}
		sort(m+1,m+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j].s=dp[i][j].s1=dp[i][j].s2=dp[i][j].s3=0;
			}
		}
		dp[1][1].s=m[1].a,dp[1][2].s=m[1].b,dp[1][3].s=m[1].c;
		dp[1][1].s1=dp[1][2].s2=dp[1][3].s3=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(j==1){
						if(dp[i-1][k].s1==n/2) continue;
						if(dp[i-1][k].s+m[i].a>dp[i][j].s){
							dp[i][j].s=dp[i-1][k].s+m[i].a;
							dp[i][j].s1=dp[i-1][k].s1+1;
							dp[i][j].s2=dp[i-1][k].s2;
							dp[i][j].s3=dp[i-1][k].s3;
						}
					}
					if(j==2){
						if(dp[i-1][k].s2==n/2) continue;
						if(dp[i-1][k].s+m[i].b>dp[i][j].s){
							dp[i][j].s=dp[i-1][k].s+m[i].b;
							dp[i][j].s1=dp[i-1][k].s1;
							dp[i][j].s2=dp[i-1][k].s2+1;
							dp[i][j].s3=dp[i-1][k].s3;
						}
					}
					if(j==3){
						if(dp[i-1][k].s3==n/2) continue;
						if(dp[i-1][k].s+m[i].c>dp[i][j].s){
							dp[i][j].s=dp[i-1][k].s+m[i].c;
							dp[i][j].s1=dp[i-1][k].s1;
							dp[i][j].s2=dp[i-1][k].s2;
							dp[i][j].s3=dp[i-1][k].s3+1;
						}
					}
				}
			}
		}
		cout<<max(dp[n][1].s,max(dp[n][2].s,dp[n][3].s))<<"\n";
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
