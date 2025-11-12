#include<bits/stdc++.h>
using namespace std;
#define N 125412
bool cmp(int a,int b){
	return a>b; 
}
int club[4][N],dp[205][5][105],n,i11,ans;
bool fl=0,ag=0;
void solv2(){
	sort(club[1]+1,club[1]+n+1,cmp);
	for(int i=1;i<=(n/2);i++){
		ans+=club[1][i];
	}
	cout<<ans<<"\n";
}void solv3(){
	dp[1][1][1]=club[1][1];
	dp[1][2][1]=club[2][1];
	for(int i=2;i<n;i++){
		for(int k=max(i-(n/2)-1,0);k<=min(i,n/2);k++){
			dp[i][1][k]=max(dp[i][1][k],dp[i-1][1][k-1]+dp[i-1][2][i-k-1]+club[1][i]);
			dp[i][2][k]=max(dp[i][2][k],dp[i-1][2][k-1]+dp[i-1][1][i-k-1]+club[2][i]);
		}
	}
	int i=n;
	for(int k=max(i-(n/2)-1,0);k<=min(i,n/2);k++){
		int m=n-k;
		for(int l=max(m-(n/2),0);l<=min(m,n/2);l++){
			ans=max(ans,dp[i-1][1][k-1]+dp[i-1][2][i-k-1]+club[1][i]);
			ans=max(ans,dp[i-1][2][k-1]+dp[i-1][1][i-k-1]+club[2][i]);
		}
	}
	cout<<ans<<"\n";
}
void solv4(){
	dp[1][1][1]=club[1][1];
	dp[1][2][1]=club[2][1];
	dp[1][3][1]=club[3][1];
	for(int i=2;i<n;i++){
		for(int k=0;k<min(i,n/2);k++){
			int m=n-k;
			for(int l=max(m-(n/2),0);l<=min(m,n/2);l++){
				dp[i][1][k]=max(dp[i][1][k],dp[i-1][1][k-1]+dp[i-1][2][l]+dp[i-1][3][m-l]+club[1][i]);
				dp[i][2][k]=max(dp[i][2][k],dp[i-1][2][k-1]+dp[i-1][3][l]+dp[i-1][1][m-l]+club[2][i]);
				dp[i][3][k]=max(dp[i][3][k],dp[i-1][3][k-1]+dp[i-1][1][l]+dp[i-1][2][m-l]+club[3][i]);
			}
		}
	}
	int i=n;
	for(int k=0;k<min(i,n/2);k++){
		int m=n-k;
		for(int l=max(m-(n/2),0);l<=min(m,n/2);l++){
			ans=max(ans,dp[i-1][1][k-1]+dp[i-1][2][l]+dp[i-1][3][m-l]+club[1][i]);
			ans=max(ans,dp[i-1][2][k-1]+dp[i-1][3][l]+dp[i-1][1][m-l]+club[2][i]);
			ans=max(ans,dp[i-1][3][k-1]+dp[i-1][1][l]+dp[i-1][2][m-l]+club[3][i]);
		}
	}
	cout<<ans<<"\n";
}
void init9998(){
	ans=0;
	memset(club,0,sizeof(club));
	memset(dp,0,sizeof(dp));
	cin>>n;//11
	for(int i=1;i<=n;i++){
		cin>>club[1][i];
		cin>>club[2][i];
		if(club[2][i]!=0) fl=true;
		cin>>club[3][i];
		if(club[3][i]!=0) 	ag=true;
		//club1[j][i].val=club[j][i];
		//club1[j][i].ta=i;
	}
	
	if(!fl) solv2();
	else if(!ag) solv3(); 
	else solv4();
} 
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		init9998();
	}
	return 0;
	//fclose(stdin);
	//fclose(stdout);
} 
