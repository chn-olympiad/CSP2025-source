#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e3+7;
long long dp[N][N],s[N][N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m,i,j,k,l;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>s[i][i];
		dp[i][i]=(s[i][i]==m?1ll:0ll);
	}
	for(l=1;l<n;l++){
		for(i=0;l+i<n;i++){
			j=l+i;
			for(k=i;k<j;k++){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
			s[i][j]=s[i][j-1]^s[j][j];
			dp[i][j]=max(dp[i][j],(s[i][j]==m?1ll:0ll));
		}
	}
	cout<<dp[0][n-1];
	return 0;
}

