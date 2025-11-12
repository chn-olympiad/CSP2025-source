#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x1,x2,x3,x;
};
node a[100010];
node dp[100010][4];
bool cmp1(node l1,node l2){
	return l1.x1>l2.x1;
}
bool cmp2(node l1,node l2){
	return l1.x2>l2.x2;
}
bool cmp3(node l1,node l2){
	return l1.x3>l2.x3;
}
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
		}
		long long ans1,ans2,ans3;
		sort(a+1,a+n+1,cmp1);
		dp[1][1].x=a[1].x1;
		dp[1][1].x1++;
		dp[1][2].x=a[2].x2;
		dp[1][2].x2++;
		dp[1][3].x=a[3].x3;
		dp[1][3].x3++;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int h=1;h<=3;h++){
					if(j==1){
						if(dp[i-1][h].x1+1<=n/2){
							if(dp[i-1][h].x+a[i].x1>dp[i][j].x){
								dp[i][j].x1=dp[i-1][h].x1+1;
								dp[i][j].x3=dp[i-1][h].x3;
								dp[i][j].x2=dp[i-1][h].x2;
							}
							dp[i][j].x=max(dp[i-1][h].x+a[i].x1,dp[i][j].x);
						}
					}
					if(j==2){
						if(dp[i-1][h].x2+1<=n/2){
							if(dp[i-1][h].x+a[i].x2>dp[i][j].x){
								dp[i][j].x2=dp[i-1][h].x2+1;
								dp[i][j].x1=dp[i-1][h].x1;
								dp[i][j].x3=dp[i-1][h].x3;
							}
							dp[i][j].x=max(dp[i-1][h].x+a[i].x2,dp[i][j].x);
						}
					}
					if(j==3){
						if(dp[i-1][h].x3+1<=n/2){
							if(dp[i-1][h].x+a[i].x3>dp[i][j].x){
								dp[i][j].x3=dp[i-1][h].x3+1;
								dp[i][j].x2=dp[i-1][h].x2;
								dp[i][j].x1=dp[i-1][h].x1;
							}
							dp[i][j].x=max(dp[i-1][h].x+a[i].x3,dp[i][j].x);
						}
					}
				}
			}
		}
		ans1=max({dp[n][1].x,dp[n][2].x,dp[n][3].x});
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j].x=dp[i][j].x1=dp[i][j].x2=dp[i][j].x3=0;
			}
		}
		sort(a+1,a+n+1,cmp2);
		dp[1][1].x=a[1].x1;
		dp[1][1].x1++;
		dp[1][2].x=a[2].x2;
		dp[1][2].x2++;
		dp[1][3].x=a[3].x3;
		dp[1][3].x3++;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int h=1;h<=3;h++){
					if(j==1){
						if(dp[i-1][h].x1+1<=n/2){
							if(dp[i-1][h].x+a[i].x1>dp[i][j].x){
								dp[i][j].x1=dp[i-1][h].x1+1;
								dp[i][j].x3=dp[i-1][h].x3;
								dp[i][j].x2=dp[i-1][h].x2;
							}
							dp[i][j].x=max(dp[i-1][h].x+a[i].x1,dp[i][j].x);
						}
					}
					if(j==2){
						if(dp[i-1][h].x2+1<=n/2){
							if(dp[i-1][h].x+a[i].x2>dp[i][j].x){
								dp[i][j].x2=dp[i-1][h].x2+1;
								dp[i][j].x1=dp[i-1][h].x1;
								dp[i][j].x3=dp[i-1][h].x3;
							}
							dp[i][j].x=max(dp[i-1][h].x+a[i].x2,dp[i][j].x);
						}
					}
					if(j==3){
						if(dp[i-1][h].x3+1<=n/2){
							if(dp[i-1][h].x+a[i].x3>dp[i][j].x){
								dp[i][j].x3=dp[i-1][h].x3+1;
								dp[i][j].x2=dp[i-1][h].x2;
								dp[i][j].x1=dp[i-1][h].x1;
							}
							dp[i][j].x=max(dp[i-1][h].x+a[i].x3,dp[i][j].x);
						}
					}
				}
			}
		}
		ans2=max({dp[n][1].x,dp[n][2].x,dp[n][3].x});
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j].x=dp[i][j].x1=dp[i][j].x2=dp[i][j].x3=0;
			}
		}
		sort(a+1,a+n+1,cmp3);
		dp[1][1].x=a[1].x1;
		dp[1][1].x1++;
		dp[1][2].x=a[2].x2;
		dp[1][2].x2++;
		dp[1][3].x=a[3].x3;
		dp[1][3].x3++;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int h=1;h<=3;h++){
					if(j==1){
						if(dp[i-1][h].x1+1<=n/2){
							if(dp[i-1][h].x+a[i].x1>dp[i][j].x){
								dp[i][j].x1=dp[i-1][h].x1+1;
								dp[i][j].x3=dp[i-1][h].x3;
								dp[i][j].x2=dp[i-1][h].x2;
							}
							dp[i][j].x=max(dp[i-1][h].x+a[i].x1,dp[i][j].x);
						}
					}
					if(j==2){
						if(dp[i-1][h].x2+1<=n/2){
							if(dp[i-1][h].x+a[i].x2>dp[i][j].x){
								dp[i][j].x2=dp[i-1][h].x2+1;
								dp[i][j].x1=dp[i-1][h].x1;
								dp[i][j].x3=dp[i-1][h].x3;
							}
							dp[i][j].x=max(dp[i-1][h].x+a[i].x2,dp[i][j].x);
						}
					}
					if(j==3){
						if(dp[i-1][h].x3+1<=n/2){
							if(dp[i-1][h].x+a[i].x3>dp[i][j].x){
								dp[i][j].x3=dp[i-1][h].x3+1;
								dp[i][j].x2=dp[i-1][h].x2;
								dp[i][j].x1=dp[i-1][h].x1;
							}
							dp[i][j].x=max(dp[i-1][h].x+a[i].x3,dp[i][j].x);
						}
					}
				}
			}
		}
		ans3=max({dp[n][1].x,dp[n][2].x,dp[n][3].x});
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j].x=dp[i][j].x1=dp[i][j].x2=dp[i][j].x3=0;
			}
		}
		cout<<max({ans1,ans2,ans3})<<endl;
	}	
	return 0;
}
