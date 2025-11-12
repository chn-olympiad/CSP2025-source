#include<bits/stdc++.h>
using namespace std;
int t,n;
struct Dps{
	int val;
	int c1,c2,c3;
}dp[100005][4];
int v[100005][4];
int big2;
int maxx(int x,int y,int z){
	int t1=max(x,y);
	return max(t1,z);
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			dp[i][1]={0,0,0,0};
			dp[i][2]={0,0,0,0};
			dp[i][3]={0,0,0,0};
		}
		big2=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&v[i][1],&v[i][2],&v[i][3]);
		}
		for(int i=1;i<=n;i++){
			dp[i][1].val=maxx(dp[i-1][1].val+v[i][1],dp[i-1][2].val+v[i][1],dp[i-1][3].val+v[i][1]);
			if(dp[i][1].val==dp[i-1][1].val+v[i][1]&&dp[i-1][1].c1+1<=n/2){
				dp[i][1].c1=dp[i-1][1].c1+1;
			}else if(dp[i][1].val==dp[i-1][2].val+v[i][1]&&dp[i-1][2].c1+1<=n/2){
				dp[i][1].c1=dp[i-1][2].c1+1;
			}else if(dp[i-1][3].c1+1<=n/2){
				dp[i][1].c1=dp[i-1][3].c1+1;
			}
			dp[i][2].val=maxx(dp[i-1][1].val+v[i][2],dp[i-1][2].val+v[i][2],dp[i-1][3].val+v[i][2]);
			if(dp[i][2].val==dp[i-1][1].val+v[i][2]&&dp[i-1][1].c2+1<=n/2){
				dp[i][2].c2=dp[i-1][1].c2+1;
			}else if(dp[i][2].val==dp[i-1][2].val+v[i][2]&&dp[i-1][2].c2+1<=n/2){
				dp[i][2].c2=dp[i-1][2].c2+1;
			}else if(dp[i-1][3].c2+1<=n/2){
				dp[i][2].c2=dp[i-1][3].c2+1;
			}
			dp[i][3].val=maxx(dp[i-1][1].val+v[i][3],dp[i-1][2].val+v[i][3],dp[i-1][3].val+v[i][3]);
			if(dp[i][3].val==dp[i-1][1].val+v[i][3]&&dp[i-1][1].c3+1<=n/2){
				dp[i][3].c3=dp[i-1][1].c3+1;
			}else if(dp[i][3].val==dp[i-1][2].val+v[i][3]&&dp[i-1][2].c3+1<=n/2){
				dp[i][3].c3=dp[i-1][2].c3+1;
			}else if(dp[i-1][3].c3+1<=n/2){
				dp[i][3].c3=dp[i-1][3].c3+1;
			}
		}
		for(int i=1;i<=3;i++){
			big2=max(big2,dp[n][i].val);
		}
		cout<<big2<<endl;
	}
	return 0;
}
