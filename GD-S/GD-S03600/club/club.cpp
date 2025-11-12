#include<bits/stdc++.h>
using namespace std;
int n,cnt,vis[100005],x,y,z;
struct node{
	int x,no;
}a[100005],b[100005],c[100005];
bool cmp(node i,node j){
	return i.x>j.x;
}
int dp[2][205][205][205],t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>b[i].x>>c[i].x;
			a[i].no=b[i].no=c[i].no=i;
		}
		if(n<=200){
			memset(dp,-0x3f,sizeof(dp));
			dp[0][0][0][0]=0;
			for(int i=1;i<=n+1;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						for(int h=0;h<=n/2;h++){
							dp[i&1][j][k][h]=-0x3f3f3f3f;
						}
					}
				}
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=min(n/2,n-j);k++){
						for(int h=0;h<=min(n/2,n-j-k);h++){
							if(h+1<=min(n/2,n-j-k)) dp[i&1][j][k][h+1]=max(dp[i&1][j][k][h+1],dp[i-1&1][j][k][h]+c[i].x);
							if(k+1<=min(n/2,n-j-h)) dp[i&1][j][k+1][h]=max(dp[i&1][j][k+1][h],dp[i-1&1][j][k][h]+b[i].x);
							if(j+1<=min(n/2,n-h-k)) dp[i&1][j+1][k][h]=max(dp[i&1][j+1][k][h],dp[i-1&1][j][k][h]+a[i].x);
						}
					}
				}
			}
			int ans=0;
			for(int j=0;j<=n/2;j++)
				for(int k=0;k<=n/2;k++){
					if(j+k<n/2) continue;
					ans=max(dp[n&1][j][k][n-j-k],ans);
				}
			cout<<ans<<endl; 
		}else{
			memset(vis,0,sizeof(vis));
			int ans=0,res=0,x=1,y=1;
			for(int i=1;i<=n/2;i++){
				ans+=a[x].x;
				vis[a[x].no]=1;
				x++;
			} 
			for(int i=1;i<=n/2;i++){
				while(vis[b[y].no]) y++; 
				ans+=b[y].x;
				vis[b[y].no]=1;
				y++;
			}
			memset(vis,0,sizeof(vis));
			for(int i=1;i<=n/2;i++){
				res+=b[y].x;
				vis[b[y].no]=1;
				y++;
			}
			for(int i=1;i<=n/2;i++){
				while(vis[a[x].no]) x++; 
				res+=a[x].x;
				vis[a[x].no]=1;
				x++;
			}
			cout<<max(ans,res)<<endl;
		}
	}
	return 0;
} 
