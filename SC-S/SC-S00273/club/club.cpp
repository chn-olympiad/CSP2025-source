#include<bits/stdc++.h>
#define ll long long
#define lb long double
using namespace std;
const int MAXN=1e5+100;
const int st=6e3;
int t,n;
ll ans;
ll dp[210][210][210];
struct node{
	ll a[4],ma;
	int fir,sec,thi;
	bool operator<(const node x)const{
		return ma>x.ma;
//		if(a[1]!=x.a[1])return a[1]<x.a[1];
//		if(a[2]!=x.a[2])return a[2]<x.a[2];
//		return a[3]<x.a[3];
	}
}da[MAXN];
int now,tmp;
int cnt[4];
bool f;
bool cmp1(node x,node y)
{
	return x.a[1]>y.a[1];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		f=0;
		cin>>n;ans=0;
		for(int i=1;i<=n;++i)
		{
			cin>>da[i].a[1]>>da[i].a[2]>>da[i].a[3];
			if(da[i].a[2]!=0||da[i].a[3]!=0)f=1;
		}
		if(n<=200)
		{
			memset(dp,-1,sizeof(dp));
			for(int i=0;i<=n;++i)dp[i][0][0]=0;
			for(int i=1;i<=n;++i)
			{
				for(int j=0;j<=n;++j)
					for(int k=0;k<=n;++k)
						dp[i][j][k]=dp[i-1][j][k];
				for(int j=0;j<=i;++j)
				{
					if(j>n/2)break;
					for(int k=0;j+k<=i;++k)
					{
//					if(i==2&&j==0&&k==1)
//					{
//						cout<<dp[i][j][k]<<'*'<<tmp<<endl;
//					}
						if(k>n/2)break;
						tmp=i-j-k;
						if(tmp>n/2)continue;
						if(j&&dp[i-1][j-1][k]!=-1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+da[i].a[1]);
						if(k&&dp[i-1][j][k-1]!=-1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+da[i].a[2]);
						
						if(tmp&&dp[i-1][j][k]!=-1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+da[i].a[3]);
						
					}
				}
			}
			for(int i=0;i<=n/2;++i)
				for(int j=0;j<=n/2;++j)if(n-i-j<=n/2)ans=max(ans,dp[n][i][j]);
			cout<<ans<<'\n';
			continue;
		}
		if(!f)
		{
			sort(da+1,da+1+n,cmp1);
			for(int i=1;i<=n/2;++i)
			{
				ans+=da[i].a[1];
			}
			cout<<ans<<'\n';
			continue;
		}
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;++i)
		{
			da[i].ma=max(da[i].a[1],da[i].a[2]);
			da[i].ma=max(da[i].ma,da[i].a[3]);
			if(da[i].a[1]>=da[i].a[2]&&da[i].a[1]>=da[i].a[3])
			{
				da[i].fir=1;
				if(da[i].a[2]>=da[i].a[3])da[i].sec=2,da[i].thi=3;
				else da[i].sec=3,da[i].thi=2;
			}
			else if(da[i].a[2]>=da[i].a[1]&&da[i].a[2]>=da[i].a[3])
			{
				da[i].fir=2;
				if(da[i].a[1]>=da[i].a[3])da[i].sec=1,da[i].thi=3;
				else da[i].sec=3,da[i].thi=1;
			}
			else{
				da[i].fir=3;
				if(da[i].a[1]>=da[i].a[2])da[i].sec=1,da[i].thi=2;
				else da[i].sec=2,da[i].thi=1;
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(cnt[da[i].fir]<n/2)ans+=da[i].ma,cnt[da[i].fir]++;
			else ans+=da[i].a[da[i].sec],++cnt[da[i].sec];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1
2
1 8 9
1 1 6

*/