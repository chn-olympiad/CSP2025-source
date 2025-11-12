#include<bits/stdc++.h>
using namespace std;
struct g{
	long long x;
	long long z;
}dp[100005][3][2];
long long t,n,a[100005][3];
g mmax(g aa,g bb){
	return (aa.z>bb.z?aa:aa.z<bb.z?bb:aa.x>bb.x?bb:aa);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		dp[1][0][1].z=a[1][0],dp[1][0][1].x=1;
		dp[1][1][1].z=a[1][1],dp[1][1][1].x=1;
		dp[1][2][1].z=a[1][2],dp[1][2][1].x=1;
		for(int i=2;i<=n;i++)
		{
			if(dp[i][0][1].x<=n/2) dp[i][0][1].z=a[i][0],dp[i][0][1].x++;
			if(dp[i][1][1].x<=n/2) dp[i][1][1].z=a[i][1],dp[i][1][1].x++;
			if(dp[i][2][1].x<=n/2) dp[i][2][1].z=a[i][2],dp[i][2][1].x++;
			g maxx=mmax(mmax(mmax(dp[i-1][0][0],dp[i-1][0][1]),mmax(dp[i-1][1][0],dp[i-1][1][1])),mmax(dp[i-1][2][0],dp[i-1][2][1]));
			dp[i][0][1].z+=maxx.z,dp[i][0][1].x+=maxx.x;
			dp[i][0][0].z=maxx.z,dp[i][0][0].x=maxx.x;
			dp[i][1][1].z+=maxx.z,dp[i][1][1].x+=maxx.x;
			dp[i][1][0].z=maxx.z,dp[i][1][0].x=maxx.x;
			dp[i][2][1].z+=maxx.z,dp[i][2][1].x+=maxx.x;
			dp[i][2][0].z=maxx.z,dp[i][2][0].x=maxx.x;
		}
		cout<<max(max(max(dp[n][0][0].z,dp[n][0][1].z),max(dp[n][1][0].z,dp[n][1][1].z)),max(dp[n][2][0].z,dp[n][2][1].z))<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
