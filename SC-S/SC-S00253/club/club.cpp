#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10,maxv=1e1+5,maxn2=2e2+10;
const ll inf=1e18+10;
int t,n;
int use[maxv],cnt[maxv],win[maxn][3];
ll ans;
ll dp[2][maxn2][maxn2];
struct STU{
	int Ax,Ay,Bx,By;
}a[maxn];
bool cmp(STU x,STU y) {return x.Ax>y.Ax;}
int read()
{
	int ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
void inpu()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		use[1]=read(),use[2]=read(),use[3]=read();
		for(int j=1;j<=3;j++) win[i][j]=use[j];
		int Ax=0,Bx=0,Ay=0,By=0;
		for(int j=1;j<=3;j++)
		{
			if(use[j]>=Ax)
			{
				Bx=Ax,By=Ay;
				Ax=use[j],Ay=j;
			}else if(use[j]>=Bx) Bx=use[j],By=j;
		}
		a[i].Ax=Ax,a[i].Ay=Ay-1,a[i].Bx=Bx,a[i].By=By-1;
//		cout<<"i="<<i<<" Ax="<<a[i].Ax<<" Bx="<<a[i].Bx<<'\n';
	}
}
void deal()
{
	ans=cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i].Bx;//cout<<"i="<<i<<" Bx="<<a[i].Bx<<'\n';
		a[i].Ax-=a[i].Bx;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) if(cnt[a[i].Ay]<(n>>1)) cnt[a[i].Ay]++,ans+=a[i].Ax;
}
void DP()
{
	ans=0;
	for(int j=0;j<=n;j++) for(int p=0;p<=n;p++) dp[0][j][p]=dp[1][j][p]=-inf;
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		int now=i&1,ed=(i+1)&1;
		for(int j=0;j<=i;j++) for(int p=0;p<=i;p++) dp[now][j][p]=0;
		for(int j=0;j<=(n>>1);j++) for(int p=0;p<=(n>>1);p++)
		{
			dp[now][j][p]=max(dp[now][j][p],dp[ed][j][p]+win[i][3]);
			if(j) dp[now][j][p]=max(dp[now][j][p],dp[ed][j-1][p]+win[i][1]);
			if(p) dp[now][j][p]=max(dp[now][j][p],dp[ed][j][p-1]+win[i][2]);
//			cout<<"dp["<<i<<"]["<<j<<"]["<<p<<"]="<<dp[now][j][p]<<'\n';
		}
	}
	for(int j=0;j<=(n>>1);j++) for(int p=0;p<=(n>>1);p++) if(n-j-p<=(n>>1)) ans=max(ans,dp[n&1][j][p]);
}
void solve()
{
	inpu();
	if(n>200) deal();
	else DP();
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--) solve();
	return 0;
}