#include<bits/stdc++.h>
using namespace std;
long long a[100005][3];
long long dp[205][205][205];
long long num[100005];
int n;
long long dp1[2500][2500];
void f1(){
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++){
		num[i]=a[i][0];
	} 
	sort(num+1,num+1+n);
	long long sum=0;
	for(int i=n;i>=1;i--){
		sum+=num[i];
	}
	cout<<sum<<"\n";
}
void f2(){
	memset(dp1,0,sizeof(dp1));
	for(int r=1;r<=n;r++){
		for(int i=n/2;i>=1;i--){
			for(int j=n/2;j>=1;j--){
				dp1[i][j]=max(dp1[i][j],max(dp1[i-1][j]+a[r][0],dp1[i][j-1]+a[r][1]));
			}
		}
	}
	cout<<dp1[n/2][n/2]<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		
		cin>>n;
		int flag1=1;
		int flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][1]!=0||a[i][2]!=0){
				flag1=0;
			}
			if(a[i][2]!=0){
				flag=0;
			}
		}
		if(n==2){
			int num1=max(a[1][0]+a[2][1],a[1][1]+a[2][0]);
			int num2=max(a[1][0]+a[2][2],a[1][2]+a[2][0]);
			int num3=max(a[1][1]+a[2][2],a[1][2]+a[2][1]);
			cout<<max(num1,max(num2,num3))<<"\n";
			continue;
		}
		if(flag1){
			f1();
			continue;
		}
		else if(flag){
			f2();
			continue;
		}
		else {
			for(int s=1;s<=n;s++){
				for(int i=n/2;i>=1;i--){
					for(int j=n/2;j>=1;j--){
						for(int r=n/2;r>=1;r--){
							dp[i][j][r]=max(max(dp[i][j][r],dp[i][j][r-1]+a[s][2]),max(dp[i][j-1][r]+a[s][1],dp[i-1][j][r]+a[s][0]));
						}
					}
				}
			}
			
		}
		cout<<dp[n/2][n/2][n/2]<<"\n";
	}
	return 0;
}
