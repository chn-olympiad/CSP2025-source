# include<bits/stdc++.h>
using namespace std;
int n,m,dp[19][19][1<<18],c[20],s[20],ans;
char ipt;
void add(int &x,int y){x+=y;x-=x>=998244353?998244353:0;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>ipt,s[i]=ipt-'0';
	for(int i = 0;i<n;i++)cin>>c[i];
	dp[0][0][0]=1;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<1<<n;j++)
		for(int k=0;k<i;k++)
		if(dp[i-1][k][j])
		for(int l = 0;l<n;l++)
		if((j&(1<<l))==0){
			if(k>=c[l]||!s[i])add(dp[i][k+1][j|(1<<l)],dp[i-1][k][j]);
			else add(dp[i][k][j|(1<<l)],dp[i-1][k][j]);
		}
	}
	for(int j = 0;j<=n-m;j++)add(ans,dp[n][j][(1<<n)-1]);
	cout<<ans;
}
