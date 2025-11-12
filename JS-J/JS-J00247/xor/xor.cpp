#include<bits/stdc++.h>
using namespace std;
long long a[500005],xo[500005],k;
int n,dp[4][500005],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			xo[j]=xo[j]^a[i+j-1];
			int xx;
			if(i==1)xx=0;
			else if((i-1)%3==0)xx=3;
			else xx=(i-1)%3;
			int yy;
			if(i==1||i==2)yy=0;
			else if((xx-1)%3==0)yy=3;
			else yy=(xx-1)%3;
			dp[(i-1)%3+1][j]=max(dp[xx][j]+dp[xx][j+1]-dp[yy][j+1],(int)(xo[j]==k));
		}
	}
	cout<<dp[(n-1)%3+1][1];
	return 0;
}
