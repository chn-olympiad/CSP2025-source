#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t;
int n;
int x,y,z;
int ans;
int dp[N][4];
struct man{
	int w[4];
}a[N];
bool cmp(man xx,man yy)
{
	int mx=max(xx.w[1],max(xx.w[2],xx.w[3]));
	int my=max(yy.w[1],max(yy.w[2],yy.w[3]));
	return mx>my;
}
void solve(int r,int x,int y,int z,int sum)
{
	if(r>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(x<n/2)
		solve(r+1,x+1,y,z,sum+a[r].w[1]);
	if(y<n/2)
		solve(r+1,x,y+1,z,sum+a[r].w[2]);
	if(z<n/2)
		solve(r+1,x,y,z+1,sum+a[r].w[3]);
	
	return;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(dp,-127,sizeof(dp));
		dp[0][1]=dp[0][2]=dp[0][3]=0;
		x=0,y=0,z=0,ans=0;
		int anss=0;
		for(int i=1;i<=n;i++)
			cin>>a[i].w[1]>>a[i].w[2]>>a[i].w[3];
		sort(a+1,a+1+n,cmp);
		solve(1,0,0,0,0);
		/*for(int i=1;i<=n;i++)
			for(int j=20000;j>=1;j--)
				for(int k=1;k<=3;k++)
					for(int l=1;l<=3;l++)
					dp[i][j]=max(dp[i][j],dp[i-a[i].w[k]][l]);
				
		for(int i=1;i<=20000;i++)
			for(int j=1;j<=3;j++)
				if(dp[i][j])
					anss=i;
		cout<<anss<<"\n";*/
		cout<<ans<<"\n";
	}
	return 0;
}


