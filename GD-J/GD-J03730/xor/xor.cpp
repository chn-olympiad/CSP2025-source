#include<bits/stdc++.h>
using namespace std;
const int M=5114;
int n,k,flag;
int a[M],s[M],l;
int dp[M][M];
int main(){
	freopen("xor1.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	int x=s[3]^s[2];
    cout<<x;
	for(int j=1;j<=n;j++){
		for(int i=j;i>0;i--){
			if(s[j]^s[i-1]==k) flag=1;
			dp[i][j]=flag;
			for(int m=i;m<j;m++){
				if(dp[i][m]+dp[m+1][j]>dp[i][j]) dp[i][j]=dp[i][m]+dp[m+1][j];
			} 
			flag=0;
		}
	}
	cout<<dp[1][1]<<' '<<dp[3][3]<<' ';
	cout<<dp[1][n];
	//int s=1^2^3^3;
	//cout<<s;
	//fclose(stdin);fclose(stdout);
	return 0;
}
