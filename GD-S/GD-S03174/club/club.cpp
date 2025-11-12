#include<bits/stdc++.h>
using namespace std;
const int N=200+5;
int t;
int n;
struct Node{
	int x,y,z;
}a[N];
int dp[N][N/2][N/2];
bool cmp(Node x,Node y){
	return x.y-x.z>y.y-y.z;
}
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					dp[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			a[i].x=x;
			a[i].y=y;
			a[i].z=z;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(j+k>i)continue;
					int z=i-j-k;
					if(z>n/2||z>i)continue;
					if(z!=0&&j!=i&&k!=i)dp[i][j][k]=max(dp[i-1][j][k]+a[i].z,dp[i][j][k]);
					if(k!=0&&j!=i&&z!=i)dp[i][j][k]=max(dp[i-1][j][k-1]+a[i].y,dp[i][j][k]);
					if(j!=0&&k!=i&&z!=i)dp[i][j][k]=max(dp[i-1][j-1][k]+a[i].x,dp[i][j][k]);
				}
			}
		}
//		cout<<ans<<"\n";
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
//				cout<<dp[n][i][j]<<"\n";
				ans=max(ans,dp[n][i][j]);
//				cout<<ans<<"\n";
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
