#include<bits/stdc++.h>
using namespace std;
int n,t,dp[100005][3][2],a[100005][2],x,y,z;
void msort(int l,int r,int k){
	if(l==r)return;
	int mid=(l+r)/2;
	msort(l,mid,k);
	msort(mid+1,r,k);
	int i=l,j=mid+1,cnt=l;
	while(i<=mid&&j<=r){
		if(dp[i][k][1]<=dp[j][k][1]){
			a[cnt][0]=dp[i][k][0];
			a[cnt++][1]=dp[i++][k][1];
		}else{
			a[cnt][0]=dp[j][k][0];
			a[cnt++][1]=dp[j++][k][1];
		}
	}
	while(i<=mid){
		a[cnt][0]=dp[i][k][0];
		a[cnt++][1]=dp[i++][k][1];
	}
	while(j<=r){
		a[cnt][0]=dp[j][k][0];
		a[cnt++][1]=dp[j++][k][1];
	}
	for( i=l;i<=r;i++){
		dp[i][k][1]=a[i][1];
		dp[i][k][0]=a[i][0];
	}
}
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>dp[i][0][1]>>dp[i][1][1]>>dp[i][2][1];
		}
		msort(1,n,0);
		msort(1,n,1);
		msort(1,n,2);
		for(int i=n;i>=n/2;i--){
			if(dp[i][0][0]!=dp[i][1][0]&&dp[i][2][0]!=dp[i][1][0]&&dp[i][0][0]!=dp[i][2][0]){
				ans+=dp[i][0][1];
				ans+=dp[i][1][1];
				ans+=dp[i][2][1];
			}
		}
		cout<<ans<<endl;
	}
	 
	
	return 0;
} 
