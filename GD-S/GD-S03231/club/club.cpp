#include<bits/stdc++.h>
using namespace std;
int a[100001][4];
int dp[100001][4];
int sum1,sum2,sum3;
int v[50001];
int top=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		sum1=sum2=sum3=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			int k=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
			dp[i][1]=k+a[i][1];
			dp[i][2]=k+a[i][2];
			dp[i][3]=k+a[i][3];
			if(dp[i][1]>dp[i][2]&&dp[i][1]>dp[i][3]){
				sum1++;
			}
			else if(dp[i][1]<dp[i][2]&&dp[i][2]>dp[i][3]){
				sum2++;
			}
			else if(dp[i][3]>dp[i][2]&&dp[i][1]<dp[i][3]){
				sum3++;
			}
		}
		int k=max(dp[n][1],max(dp[n][2],dp[n][3]));
		top=0;
		if(sum1>n/2){
			for(int i=1;i<=n;i++){
				if(dp[i][1]>dp[i][2]&&dp[i][1]>dp[i][3]){
					v[++top]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
				}
			}
			sort(v+1,v+top+1,cmp);
			for(int i=1;i<=sum1-n/2;i++){
				k+=v[i];
			}
		}
		else if(sum2>n/2){
			for(int i=1;i<=n;i++){
				if(dp[i][2]>dp[i][1]&&dp[i][2]>dp[i][3]){
					v[++top]=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
				}
			}
			sort(v+1,v+top+1,cmp);
			for(int i=1;i<=sum2-n/2;i++){
				k+=v[i];
			}
		}
		else if(sum3>n/2){
			for(int i=1;i<=n;i++){
				if(dp[i][3]>dp[i][2]&&dp[i][3]>dp[i][1]){
					v[++top]=max(a[i][1]-a[i][3],a[i][2]-a[i][3]);
				}
			}
			sort(v+1,v+top+1,cmp);
			for(int i=1;i<=sum3-n/2;i++){
				k+=v[i];
			}
		}
		cout<<k<<endl;
	}
	return 0;
} 
