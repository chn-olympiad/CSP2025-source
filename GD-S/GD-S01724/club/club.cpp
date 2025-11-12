#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}p[100001];
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool flag2=1;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].c!=0)flag2=0;
		}if(flag2){
			int dp[2][2501]={0},ans=-1;
			for(int i=1;i<=n;i++){
				for(int x=0;x<=min(i,n/2);x++){
					int y=i-x;
					if(y>n/2)continue;
					if(x>0)dp[i%2][x]=max(dp[(i-1)%2][x-1]+p[i].a,dp[i%2][x]);
					if(y>0)dp[i%2][x]=max(dp[(i-1)%2][x]+p[i].b,dp[i%2][x]);
					if(i==n)ans=max(ans,dp[n%2][x]);
				}
			}
			cout<<ans<<endl;
		}else{
			int dp[2][501][501]={0},ans=-1;
			for(int i=1;i<=n;i++){
				for(int x=0;x<=min(i,n/2);x++){
					for(int y=0;y<=min(i-x,n/2);y++){
						int z=i-x-y;
						if(z>n/2)continue;
						if(x>0)dp[i%2][x][y]=max(dp[(i-1)%2][x-1][y]+p[i].a,dp[i%2][x][y]);
						if(y>0)dp[i%2][x][y]=max(dp[(i-1)%2][x][y-1]+p[i].b,dp[i%2][x][y]);
						if(z>0)dp[i%2][x][y]=max(dp[(i-1)%2][x][y]+p[i].c,dp[i%2][x][y]);
						if(i==n)ans=max(ans,dp[n%2][x][y]);
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
