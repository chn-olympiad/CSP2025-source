#include<bits/stdc++.h>
using namespace std;
int t,n,k,b[5],dp[205][105][105];
struct node{
	int x,y,z,b;
}a[100005],f[100005][3];
bool cmp(node a,node b){
	return a.b>b.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;k=n/2;
		int flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].z)flag=1;
			a[i].b=a[i].y-a[i].x;
		}
		if(!flag){
			long long ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(i<=n/2){
					ans+=a[i].y;
				}
				else ans+=a[i].x;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(n<=200){
			memset(dp,0xaa,sizeof(dp));
			dp[0][0][0]=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					for(int k=0;k<=min(i,n/2);k++){
						if(i-j-k<=n/2){
							dp[i][j][k]=dp[i-1][j][k]+a[i].z;
							if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i].x);
							if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].y);
						}
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if(n-i-j<=n/2){
						ans=max(ans,dp[n][i][j]);
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		memset(b,0,sizeof(b));
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				b[1]++;
			}if(a[i].y>a[i].x&&a[i].y>a[i].z){
				b[2]++;
			}if(a[i].z>a[i].y&&a[i].z>a[i].x){
				b[3]++;
			}
			ans+=max(a[i].x,max(a[i].y,a[i].z));
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}
