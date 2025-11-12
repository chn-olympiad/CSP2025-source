#include<bits/stdc++.h>
using namespace std;
int dp[330000],n;
int t;
int a[110000][4],b[4];
void p(int j,int k){
	b[k]++;
	if(j>n||b[1]>(n/2)||b[2]>(n/2)||b[3]>(n/2)) return;
	dp[j] = max(dp[j],dp[j-1]+a[j][k]);
	for(int i=1;i<=3;i++){
		p(j+1,i); b[i]--;
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j = 0;j<=3;j++) b[j] = 0;
		for(int j = 0;j<=330000;j++) dp[j]=0;
		cin>>n;
		for(int j=1;j<=n;j++) cin>>a[j][1]>>a[j][2]>>a[j][3];
		for(int k = 1;k<=3;k++){
			dp[1]=0;
			p(1,k);
			b[k]--;
		}
		cout<<dp[n];
	}
	return 0;
}
