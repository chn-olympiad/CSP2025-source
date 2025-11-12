#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z;
}a[100005];
struct node2{
	int n=0,a=0,b=0,c=0;
};
bool cmp(node x,node y){return x.x+x.y+x.z>y.x+y.y+y.z;}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp);
		node2 dp[100005][4]={};
		for(int i=1;i<=n;i++){
			short temp=0;
			if(dp[i-1][1].a<=n/2-1){
				dp[i][1].n=dp[i-1][1].n;
				temp=1;
			}
			if(dp[i-1][2].n>dp[i][1].n&&dp[i-1][2].a<=n/2-1){
				dp[i][1].n=dp[i-1][2].n;
				temp=2;
			}
			if(dp[i-1][3].n>dp[i][1].n&&dp[i-1][3].a<=n/2-1){
				dp[i][1].n=dp[i-1][3].n;
				temp=3;
			}
			dp[i][1].n+=a[i].x;
			dp[i][1].b=dp[i-1][temp].b;
			dp[i][1].c=dp[i-1][temp].c;
			dp[i][1].a=dp[i-1][temp].a+1;
			//dp[i][1]
			temp=0;
			if(dp[i-1][2].b<=n/2-1){
				dp[i][2].n=dp[i-1][2].n;
				temp=2;
			}
			if(dp[i-1][1].n>dp[i][2].n&&dp[i-1][1].b<=n/2-1){
				dp[i][2].n=dp[i-1][1].n;
				temp=1;
			}
			if(dp[i-1][3].n>dp[i][2].n&&dp[i-1][3].b<=n/2-1){
				dp[i][2].n=dp[i-1][3].n;
				temp=3;
			}
			dp[i][2].n+=a[i].y;
			dp[i][2].a=dp[i-1][temp].a;
			dp[i][2].c=dp[i-1][temp].c;
			dp[i][2].b=dp[i-1][temp].b+1;
			//dp[i][2]
			temp=0;
			if(dp[i-1][3].c<=n/2-1){
				dp[i][3].n=dp[i-1][3].n;
				temp=3;
			}
			if(dp[i-1][1].n>dp[i][3].n&&dp[i-1][1].c<=n/2-1){
				dp[i][3].n=dp[i-1][1].n;
				temp=1;
			}
			if(dp[i-1][2].n>dp[i][3].n&&dp[i-1][2].c<=n/2-1){
				dp[i][3].n=dp[i-1][2].n;
				temp=2;
			}
			dp[i][3].n+=a[i].z;
			dp[i][3].a=dp[i-1][temp].a;
			dp[i][3].b=dp[i-1][temp].b;
			dp[i][3].c=dp[i-1][temp].c+1;
			//dp[i][3]
		}
		cout<<max(dp[n][1].n,max(dp[n][2].n,dp[n][3].n))<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
