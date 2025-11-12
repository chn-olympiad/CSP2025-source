#include<bits/stdc++.h>
using namespace std;
struct people{
	long long a,b,c;
}myd[100010];
bool cmp(people x,people y)
{
	if(x.a>=y.a)return true;
	else return false;
}
long long t[4],n,sx,dan;
void dps(long long wz,long long ans)
{
	if(t[1]<=sx&&t[2]<=sx&&t[3]<=sx)
	{
		if(wz==n+1)dan=max(dan,ans);
		else
		{
			for(int i=1;i<=3;i++)
			{
				t[i]+=1;
				int my;
				i==1?my=myd[wz].a:(i==2?my=myd[wz].b:my=myd[wz].c);
				dps(wz+1,ans+my);
				t[i]-=1;
			}
		}
	}
}
void tsdps()
{
	long long dp[505][505];
	memset(dp,0,sizeof(dp));
	dp[1][1]=myd[1].a;
	dp[1][0]=myd[1].b;
	for(long long i=2;i<=n;i++)
	{
		for(long long j=0;j<=i&&j<=sx;j++)
		{
			if(j<=sx&&i-j<=sx)
			{
				if(j==0)dp[i][j]=dp[i-1][j]+myd[i].b;
				else if(j==i)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+myd[i].a);
				else dp[i][j]=max(dp[i][j],max(dp[i-1][j]+myd[i].b,dp[i-1][j-1]+myd[i].a));
			}
			else dp[i][j]=-1;
		}
	}
	dan=dp[n][n/2];
}
void club()
{
	bool txa=true,txb=true;
	cin>>n;
	sx=n/2;
	dan=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>myd[i].a>>myd[i].b>>myd[i].c;
		if(myd[i].b!=0||myd[i].c!=0)txa=false;
		if(myd[i].c!=0)txb=false;
	}
	t[1]=t[2]=t[3]=0;
	if(n<=30)
	{
		dps(1,0);
		cout<<dan<<endl;
	}
	else if(txa)
	{
		sort(myd+1,myd+n+1,cmp);
		for(long long i=1;i<=sx;i++)dan+=myd[i].a;
		cout<<dan<<endl;
	}
	else if(txb)
	{
		tsdps();
		cout<<dan<<endl;
	}
}
int main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)club();
	return 0;
}
