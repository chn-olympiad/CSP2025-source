#include<bits/stdc++.h>
using namespace std;
int t,n,sum,az[100005][4],dp[2005][4][1005];
struct cl
{
	int a,b,c;
} ub[100005];
int cmp(cl d,cl e)
{
	return d.b>e.b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int f=0,fb=0;
		sum=0;
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=n;j++){
			cin>>ub[j].a>>ub[j].b>>ub[j].c;
			az[j][1]=ub[j].a;
			az[j][2]=ub[j].b;
			az[j][3]=ub[j].c;
			if(ub[j].a!=0){
				f=1;
			}
			if(ub[j].c!=0)
				fb=1;
		}
		if(f==0&&fb==0){
			sort(ub+1,ub+n+1,cmp);
			for(int j=1;j<=n/2;j++){
				sum+=ub[j].b;
			}
			cout<<sum<<endl;
			continue;
		}
		dp[1][1][0]=0;
		dp[1][2][0]=0;
		dp[1][3][0]=0;
		for(int j=1;j<=n;j++){
				for(int l=1;l<=n/2;l++){
					dp[j][1][l]=max(dp[j-1][1][l-1],max(dp[j-1][2][l],dp[j-1][3][l]))+az[j][1];
					dp[j][2][l]=max(dp[j-1][2][l-1],max(dp[j-1][1][l],dp[j-1][3][l]))+az[j][2];
					dp[j][3][l]=max(dp[j-1][3][l-1],max(dp[j-1][1][l],dp[j-1][2][l]))+az[j][3];
				}
		}
		cout<<max(dp[n][3][n/2],max(dp[n][2][n/2],dp[n][1][n/2]))<<endl;
	}
	return 0;
}
