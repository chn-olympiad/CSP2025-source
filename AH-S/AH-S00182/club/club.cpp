#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct stu{
	int a1;
	int a2;
	int a3;
}a[100010];
int dp[210][10][210][210];
int ma(int x,int y){
	if(x>y){
		return x;
	}
	else{
		return y;
	}
}
bool ch(stu x,stu y){
	return x.a1>y.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int j=1;j<=t;j++){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		if(n>=210){
			int ans=0;
			sort(a+1,a+1+n,ch);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int k=1;k<=3;k++){
				for(int z=1;z<=n/2;z++){
					for(int h=1;h<=n/2;h++){
						dp[i][k][z][h]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int k=1;k<=3;k++){
				for(int z=0;z<=n/2;z++){
					for(int h=0;h<=n/2;h++){
						if(h+z>i){
							continue;
						}
						if(i-h-z>n/2){
							continue;
						}
						if(k==1){
							if(z==0){
								continue;
							}
							int c=ma(dp[i-1][1][z-1][h],dp[i-1][2][z-1][h]);
							c=ma(c,dp[i-1][3][z-1][h]);
							dp[i][k][z][h]=c+a[i].a1;
						}
						if(k==2){
							if(h==0){
								continue;
							}
							int c=ma(dp[i-1][1][z][h-1],dp[i-1][2][z][h-1]);
							c=ma(c,dp[i-1][3][z][h-1]);
							dp[i][k][z][h]=c+a[i].a2;
						}
						if(k==3){
							if(z+h==i){
								continue;
							}
							int c=ma(dp[i-1][1][z][h],dp[i-1][2][z][h]);
							c=ma(c,dp[i-1][3][z][h]);
							dp[i][k][z][h]=c+a[i].a3;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n/2;i++){
			for(int k=1;k<=n/2;k++){
				if(i+k<n/2){
					continue;
				}
				else{
					ans=ma(ans,dp[n][1][i][k]);
					ans=ma(ans,dp[n][2][i][k]);
					ans=ma(ans,dp[n][3][i][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
