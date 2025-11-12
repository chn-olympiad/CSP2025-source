#include<bits/stdc++.h>
using namespace std;
struct p{
	int aa,bb,cc;
}a[1000005];
bool cmp (p x,p y){
	if(x.aa==y.aa){
		if(x.bb==y.bb){
			return x.cc>y.cc;
		}
		return x.bb>y.bb;
	}
	return x.aa>y.aa;
}
int dp[100005][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].aa>>a[i].bb>>a[i].cc;
		}
		sort(a+1,a+n+1,cmp);
		dp[1][1]=a[1].aa;
		dp[1][4]=a[1].aa;
		int r=1,r1=0,r2=0;
		for(int i=2;i<=n;i++){
			if(r<n/2){
				dp[i][1]=dp[i-1][1]+a[i].aa;
			}
			if(r1<n/2){
				dp[i][2]=dp[i-1][2]+a[i].bb;
			}
			if(r2<n/2){
				dp[i][3]=dp[i-1][3]+a[i].cc;
			}
			dp[i][4]=max(max(dp[i][1]+dp[i-1][2]+dp[i-1][3],dp[i][2]+dp[i-1][1]+dp[i-1][3]),max(dp[i][2]+dp[i-1][1]+dp[i-1][3],dp[i][3]+dp[i-1][2]+dp[i-1][1]));			
			if(dp[i][4]==dp[i][1]+dp[i-1][2]+dp[i-1][3]){
				r++;
				dp[i][1]=dp[i-1][1]+a[i].aa;
				dp[i][2]=dp[i-1][2];
				dp[i][3]=dp[i-1][3];
			}else if(dp[i][4]==dp[i][2]+dp[i-1][1]+dp[i-1][3]){
				r1++;
				dp[i][1]=dp[i-1][1];
				dp[i][2]=dp[i-1][2]+a[i].bb;
				dp[i][3]=dp[i-1][3];
			}else{
				r2++;
				dp[i][1]=dp[i-1][1];
				dp[i][2]=dp[i-1][2];
				dp[i][3]=dp[i-1][3]+a[i].cc;
			}
		}
		int maxx=dp[n][4];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=4;j++){
				dp[i][j]=0;
			}
		}
		dp[1][2]=a[1].bb;
		dp[1][4]=a[1].bb;
		r=0;
		r1=1;
		r2=0;
		for(int i=2;i<=n;i++){
			if(r<n/2){
				dp[i][1]=dp[i-1][1]+a[i].aa;
			}
			if(r1<n/2){
				dp[i][2]=dp[i-1][2]+a[i].bb;
			}
			if(r2<n/2){
				dp[i][3]=dp[i-1][3]+a[i].cc;
			}
			dp[i][4]=max(max(dp[i][1]+dp[i-1][2]+dp[i-1][3],dp[i][2]+dp[i-1][1]+dp[i-1][3]),max(dp[i][2]+dp[i-1][1]+dp[i-1][3],dp[i][3]+dp[i-1][2]+dp[i-1][1]));
			if(dp[i][4]==dp[i][1]+dp[i-1][2]+dp[i-1][3]){
				r++;
				dp[i][1]=dp[i-1][1]+a[i].aa;
				dp[i][2]=dp[i-1][2];
				dp[i][3]=dp[i-1][3];
			}else if(dp[i][4]==dp[i][2]+dp[i-1][1]+dp[i-1][3]){
				r1++;
				dp[i][1]=dp[i-1][1];
				dp[i][2]=dp[i-1][2]+a[i].bb;
				dp[i][3]=dp[i-1][3];
			}else{
				r2++;
				dp[i][1]=dp[i-1][1];
				dp[i][2]=dp[i-1][2];
				dp[i][3]=dp[i-1][3]+a[i].cc;
			}
		}
		maxx=max(maxx,dp[n][4]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=4;j++){
				dp[i][j]=0;
			}
		}
		dp[1][3]=a[1].cc;
		dp[1][4]=a[1].cc;
		r=0;
		r1=0;
		r2=1;
		for(int i=2;i<=n;i++){
			if(r<n/2){
				dp[i][1]=dp[i-1][1]+a[i].aa;
			}
			if(r1<n/2){
				dp[i][2]=dp[i-1][2]+a[i].bb;
			}
			if(r2<n/2){
				dp[i][3]=dp[i-1][3]+a[i].cc;
			}
			dp[i][4]=max(max(dp[i][1]+dp[i-1][2]+dp[i-1][3],dp[i][2]+dp[i-1][1]+dp[i-1][3]),max(dp[i][2]+dp[i-1][1]+dp[i-1][3],dp[i][3]+dp[i-1][2]+dp[i-1][1]));
			if(dp[i][4]==dp[i][1]+dp[i-1][2]+dp[i-1][3]){
				r++;
				dp[i][1]=dp[i-1][1]+a[i].aa;
				dp[i][2]=dp[i-1][2];
				dp[i][3]=dp[i-1][3];
			}else if(dp[i][4]==dp[i][2]+dp[i-1][1]+dp[i-1][3]){
				r1++;
				dp[i][1]=dp[i-1][1];
				dp[i][2]=dp[i-1][2]+a[i].bb;
				dp[i][3]=dp[i-1][3];
			}else{
				r2++;
				dp[i][1]=dp[i-1][1];
				dp[i][2]=dp[i-1][2];
				dp[i][3]=dp[i-1][3]+a[i].cc;
			}
		}
		cout<<max(maxx,dp[n][4])<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=4;j++){
				dp[i][j]=0;
			}
		}
	}
 	return 0;
}
