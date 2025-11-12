#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
	int _1,_2,_3;
}a[100005];
int dp[205][205][205]={};
int dp1[1005][1005]={};
bool cmp(st A,st B){
	return A._1-A._2>B._1-B._2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	scanf("%lld",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		memset(a,0,sizeof(a));
		int n=0;
		scanf("%lld",&n);
		bool b=1;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i]._1,&a[i]._2,&a[i]._3);
			if(a[i]._3) b=0;
		}
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n;j++){
					for(int k=0;k<=n;k++){
						if(j>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i]._1);
						if(k>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i]._2);
						if(i-j-k>=1) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i]._3);
					}
				}
			}
			int max_=0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if(n-i-j>=0&&n-i-j<=n/2) max_=max(max_,dp[n][i][j]);
				}
			}
			printf("%lld\n",max_);
		}
		else if(b){
			sort(a+1,a+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i]._1;
			}
			for(int i=n/2+1;i<=n;i++){
				sum+=a[i]._2;
			}
			printf("%lld\n",sum);
		}
		else if(n<=1000){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				for(int j=0;j<=i;j++){
					if(n-j<=n/2) dp1[i][j]=dp1[i-1][j]+a[i]._1;
					else dp1[i][j]=dp1[i-1][j]+a[i]._2;
					if(j>=1) dp1[i][j]=max(dp1[i][j],dp1[i-1][j-1]+a[i]._3);
				}
			}
		}
		else{
			int max_=0;
			int sum=0;
			int gs1=0,gs2=0,gs3=0;
			sort(a+1,a+n+1,cmp);
			sum=0;
			gs1=gs2=gs3=0;
			for(int i=1;i<=n;i++){
				if(gs1<=n/2){
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=n;i>=1;i--){
				if(gs2<=n/2){
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=1;i<=n;i++) swap(a[i]._1,a[i]._2);
			sort(a+1,a+n+1,cmp);
			sum=0;
			gs1=gs2=gs3=0;
			for(int i=1;i<=n;i++){
				if(gs1<=n/2){
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=n;i>=1;i--){
				if(gs2<=n/2){
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=1;i<=n;i++) swap(a[i]._2,a[i]._3);
			sort(a+1,a+n+1,cmp);
			sum=0;
			gs1=gs2=gs3=0;
			for(int i=1;i<=n;i++){
				if(gs1<=n/2){
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=n;i>=1;i--){
				if(gs2<=n/2){
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=1;i<=n;i++) swap(a[i]._1,a[i]._2);
			sort(a+1,a+n+1,cmp);
			sum=0;
			gs1=gs2=gs3=0;
			for(int i=1;i<=n;i++){
				if(gs1<=n/2){
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=n;i>=1;i--){
				if(gs2<=n/2){
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=1;i<=n;i++) swap(a[i]._2,a[i]._3);
			sort(a+1,a+n+1,cmp);
			sum=0;
			gs1=gs2=gs3=0;
			for(int i=1;i<=n;i++){
				if(gs1<=n/2){
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=n;i>=1;i--){
				if(gs2<=n/2){
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=1;i<=n;i++) swap(a[i]._1,a[i]._2);
			sort(a+1,a+n+1,cmp);
			sum=0;
			gs1=gs2=gs3=0;
			for(int i=1;i<=n;i++){
				if(gs1<=n/2){
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			for(int i=n;i>=1;i--){
				if(gs2<=n/2){
					if(a[i]._2>=a[i]._3||gs3==n/2) sum+=a[i]._2,gs2++;
					else sum+=a[i]._3,gs3++;
				}
				else{
					if(a[i]._1>=a[i]._3||gs3==n/2) sum+=a[i]._1,gs1++;
					else sum+=a[i]._3,gs3++;
				}
			}
			max_=max(max_,sum);
			gs1=gs2=gs3=0;
			sum=0;
			printf("%lld\n",max_);
		}
	}
	return 0;
}
