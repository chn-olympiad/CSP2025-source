#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[20005];
long long t,n,mid,ans,x2,y2,z2,dp[20005],cnt,dp1[20005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		mid=n/2;
		x2=mid,y2=mid,z2=mid;
		for(int i=1;i<=n;i++){
			for(int j=n;j>=0;j--){
				if(x2>0&&y2>0&&z2>0){
					dp[j]=max(dp[j],max(dp[j-1]+a[i].x,max(dp[j-1]+a[i].y,dp[j-1]+a[i].z)));
				}
				else if(x2>0&&y2==0&&z2>0){
					dp[j]=max(dp[j],max(dp[j-1]+a[i].x,dp[j-1]+a[i].z));
				}
				else if(x2==0&&y2>0&&z2>0){
					dp[j]=max(dp[j],max(dp[j-1]+a[i].y,dp[j-1]+a[i].z));
				}
				else if(x2>0&&y2>0&&z2==0){
					dp[j]=max(dp[j],max(dp[j-1]+a[i].y,dp[j-1]+a[i].x));
				}
				else if(x2>0&&y2==0&&z2==0){
					dp[j]=max(dp[j],dp[j-1]+a[i].x);
				}
				else if(x2==0&&y2>0&&z2==0){
					dp[j]=max(dp[j],dp[j-1]+a[i].y);
				}
				else{
					dp[j]=max(dp[j],dp[j-1]+a[i].z);
				}
			}
			cnt=max(a[i].x,max(a[i].y,a[i].z));
			if(cnt==a[i].x) x2--;
			else if(cnt==a[i].y) y2--;
			else z2--;
			//cout<<x2<<" "<<y2<<" "<<z2<<endl;
		}
		x2=mid,y2=mid,z2=mid;
		for(int i=n;i>=1;i--){
			for(int j=n;j>=0;j--){
				if(x2>0&&y2>0&&z2>0){
					dp1[j]=max(dp1[j],max(dp1[j-1]+a[i].x,max(dp1[j-1]+a[i].y,dp1[j-1]+a[i].z)));
				}
				else if(x2>0&&y2==0&&z2>0){
					dp1[j]=max(dp1[j],max(dp1[j-1]+a[i].x,dp1[j-1]+a[i].z));
				}
				else if(x2==0&&y2>0&&z2>0){
					dp1[j]=max(dp1[j],max(dp1[j-1]+a[i].y,dp1[j-1]+a[i].z));
				}
				else if(x2>0&&y2>0&&z2==0){
					dp1[j]=max(dp1[j],max(dp1[j-1]+a[i].y,dp1[j-1]+a[i].x));
				}
				else if(x2>0&&y2==0&&z2==0){
					dp1[j]=max(dp1[j],dp1[j-1]+a[i].x);
				}
				else if(x2==0&&y2>0&&z2==0){
					dp1[j]=max(dp1[j],dp1[j-1]+a[i].y);
				}
				else{
					dp1[j]=max(dp1[j],dp1[j-1]+a[i].z);
				}
			}
			cnt=max(a[i].x,max(a[i].y,a[i].z));
			if(cnt==a[i].x) x2--;
			else if(cnt==a[i].y) y2--;
			else z2--;
			//cout<<x2<<" "<<y2<<" "<<z2<<endl;
		}
		ans=max(dp1[n],dp[n]);
		cout<<ans<<endl;
	}
	return 0;
} 
