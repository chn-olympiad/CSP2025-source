#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
long long dp[2][305][305];//记得滚动 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool f1=0,f2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];	
			}
			if(a[i][3]!=0){
				f1=f2=1;
			}
		}
		if(f2==0&&n>200){
			priority_queue<int> q;
			long long sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i][1];
				q.push((a[i][2]-a[i][1]));
			}
			while((int)q.size()>n/2){
				sum+=q.top();
				q.pop();
			}
			cout<<sum<<'\n';
		}else{
			memset(dp,0,sizeof(dp));
			dp[0][0][0]=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(n/2,i);j++){
					for(int k=0;k<=min(i-j,n/2);k++){
						int l=i-j-k;
						if(j>0){
							dp[i%2][j][k]=max(dp[(i-1)%2][j-1][k]+a[i][1],dp[i%2][j][k]);
						}
						if(k>0){
							dp[i%2][j][k]=max(dp[(i-1)%2][j][k-1]+a[i][2],dp[i%2][j][k]);
						}
						if(l>0){
							dp[i%2][j][k]=max(dp[(i-1)%2][j][k]+a[i][3],dp[i%2][j][k]);
						}
					}
				}
			}
			long long ans=-1;
			for(int i=0;i<=n;i++){
				for(int j=0;j<=n-i;j++){
					int l=n-i-j;
					if(i<=n/2&&j<=n/2&&l<=n/2){
						ans=max(dp[0][i][j],ans);
					}
				}
			}
			cout<<ans<<'\n';	
		}
			
	}	
	return 0;
}