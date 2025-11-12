#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005];
int n,maxx1,maxx2,maxx3,ans,t;
int dp[205][205];
bool cmp1(node n1,node n2){
	return n1.x>n2.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof dp);
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			maxx1=max(maxx1,a[i].x);
			maxx2=max(maxx2,a[i].y);
			maxx3=max(maxx3,a[i].z);
		}
		if(maxx2==0&&maxx3==0){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
		}
		else if(maxx3==0){
			int dp[100005]={0};
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=0;j--){
					
					int k=i-j;
					if(k>n/2)continue;
					if(k>=1)
						dp[j]=dp[j]+a[i].y;
					if(j>=1)
						dp[j]=max(dp[j],dp[j-1]+a[i].x);
						
				}
			}
			ans=dp[n/2];
		}
		else{
			for(int t=1;t<=n;t++){
				for(int i=n/2;i>=0;i--){
					for(int j=n/2;j>=0;j--){
						int k=t-i-j;
						if(k>n/2)continue;
							if(k>0)
							dp[i][j]=dp[i][j]+a[t].z;
							if(i>0)
							dp[i][j]=max(dp[i-1][j]+a[t].x,dp[i][j]);
							if(j>0)
							dp[i][j]=max(dp[i][j-1]+a[t].y,dp[i][j]);
							ans=max(ans,dp[i][j]);
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
