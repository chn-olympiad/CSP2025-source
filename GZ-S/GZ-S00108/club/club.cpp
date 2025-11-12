//GZ-S00108 贵阳雅礼高级中学(贵阳市第九中学) 周正义
#include<bits/stdc++.h>
using namespace std;
struct node{
	int x1,x2,x3;
	int flag=0;
};
bool cmp(node x,node y){
	return x.x1>=y.x1; 
}
bool cmp1(node x,node y){
	return x.flag>y.flag;
}
const int maxn=1e5+10;
int t,num=0,num1=0;
int dp[maxn][3];
node a[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int a1=0,b1=0,c1=0,ans=0;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
			num+=a[i].x2;
			num+=a[i].x3;
			num1+=a[i].x3;
			if(a[i].x1>=a[i].x2)
				a[i].flag=1;

			else
				a[i].flag=2;

		}
		if(num==0){
			sort(a+1,a+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x1;
			}
			cout<<ans;
			continue;
		}
		if(num1==0){
			sort(a+1,a+1+n,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x1;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].x2;
			}
			cout<<ans;
			continue;	
		}
		dp[1][0]=a[1].x1;
		dp[1][1]=a[1].x2;
		dp[1][2]=a[1].x3;
		for(int i=2;i<=n;i++){
			int sum=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
			int sum1=max(dp[i-2][0],max(dp[i-2][1],dp[i-2][2]));
			if(sum-sum1==a[i-1].x1){
				a1++;
			}else if(sum-sum1==a[i-1].x2){
				b1++;
			}else if(sum-sum1==a[i-1].x3){
				c1++;
			}
			if(a1<n/2&&b1<n/2&&c1<n/2){
				dp[i][0]=sum+a[i].x1;
				dp[i][1]=sum+a[i].x2;
				dp[i][2]=sum+a[i].x3;
			}else if(a1<n/2&&b1<n/2&&c1>=n/2){
				dp[i][0]=sum+a[i].x1;
				dp[i][1]=sum+a[i].x2;
			}else if(a1>n/2&&b1<n/2&&c1<n/2){
				dp[i][1]=sum+a[i].x2;
				dp[i][2]=sum+a[i].x3;
			}else if(a1<n/2&&b1>n/2&&c1<n/2){
					dp[i][0]=sum+a[i].x1;
					dp[i][2]=sum+a[i].x3;
			}
		}
		cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

