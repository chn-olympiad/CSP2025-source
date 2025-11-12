#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int read()
{
	int ret=0,sgn=0,ch=getchar();
	while(!isdigit(ch)) sgn|=ch=='-',ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn ? -ret:ret;
}
struct node
{
	int a[4],id;
	friend bool operator<(const node &x,const node &y)
	{
		return x.a[x.id]>y.a[y.id];
	}
}c[MAXN];
struct sp
{
	int a[2];
	friend bool operator<(const sp &x,const sp &y)
	{
		return x.a[1]-x.a[0]<y.a[1]-y.a[0];
	}
}d[MAXN];

int n,f[4],ans;
int dp[MAXN][2];
void solve()
{
	n=read(),f[1]=f[2]=f[3]=ans=0;
	for (int i=1;i<=n;i++)
	{
		int f=-1,id=0;
		for (int j=1;j<=3;j++)
		{
			c[i].a[j]=read();
			if (c[i].a[j]>f) f=c[i].a[j],id=j;
		}
		c[i].id=id;
	}
	sort(c+1,c+n+1);
	int N=1;
	while(N<=n)
	{
		int id=c[N].id;
		if (f[id]>=n/2) break;
		ans+=c[N].a[id],f[id]++;
		N++;
	}
	if (N<=n) ans=0;
	
	int ss=0;
	for (int i=1;i<=n;i++) d[i].a[0]=c[i].a[1],d[i].a[1]=max(c[i].a[2],c[i].a[3]);
	sort(d+1,d+n+1);
	for (int i=1;i<=n/2;i++) ss+=d[i].a[0];
	for (int i=n/2+1;i<=n;i++) ss+=d[i].a[1];
	ans=max(ans,ss);
	
	ss=0;
	for (int i=1;i<=n;i++) d[i].a[0]=c[i].a[2],d[i].a[1]=max(c[i].a[1],c[i].a[3]);
	sort(d+1,d+n+1);
	for (int i=1;i<=n/2;i++) ss+=d[i].a[0];
	for (int i=n/2+1;i<=n;i++) ss+=d[i].a[1];
	ans=max(ans,ss);
	
	ss=0;
	for (int i=1;i<=n;i++) d[i].a[0]=c[i].a[3],d[i].a[1]=max(c[i].a[1],c[i].a[2]);
	sort(d+1,d+n+1);
	for (int i=1;i<=n/2;i++) ss+=d[i].a[0];
	for (int i=n/2+1;i<=n;i++) ss+=d[i].a[1];
	ans=max(ans,ss);
	
//	for (int i=1;i<=n/2;i++)
//	{
//		s[0].insert(c[i].a[1]-c[i].a[2]);
//		ss+=c[i].a[1];
//	}
//	for (int i=n/2+1;i<=n;i++)
//	{
//		s[1].insert(c[i].a[1]-c[i].a[2]);
//		ss+=c[i].a[2];
//	}
//	while(1)
//	{
//		auto f1=s[0].begin(),f2=--s[1].end();
//		int s1=*f2,s2=*f2;
//		if (*f1>*f2)
//		{
//			int s1=
//		}
//	}
	
//	for (int i=N;i<=n;i++)
//	{
//		int res=0;
//		for (int j=1;j<=3;j++)
//		  if (j!=c[i].id)
//		  {
//		  	res=max(res,c[i].a[j]);
//		  }
//		ans+=res;
//	}
//	cout<<ans<<endl;return;
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=1;j<=3;j++) cout<<c[i].a[j]<<" ";
//		cout<<c[i].id;
//		cout<<endl;
//	}
//	cout<<endl;

//	int nw,pr;
//	for (int i=0;i<=n;i++) dp[i][0]=dp[i][1]=-1;
//	dp[0][0]=0,nw=0,pr=1;
//	for (int i=1;i<=n;i++)
//	{
//		swap(nw,pr);
//		for (int j=0;j<=n;j++)
//		{
//			if (~dp[j][pr])
//			{
//				dp[j+1][nw]=max(dp[j+1][nw],dp[j][pr]+c[i].a[1]);
//				dp[j][nw]=max(dp[j][nw],dp[j][pr]+max(c[i].a[2],c[i].a[3]));
//			}
//		}
//	}
//	ans=max(dp[n/2][nw],ans);
//	
//	for (int i=0;i<=n;i++) dp[i][0]=dp[i][1]=-1;
//	dp[0][0]=0,nw=0,pr=1;
//	for (int i=1;i<=n;i++)
//	{
//		swap(nw,pr);
//		for (int j=0;j<=n;j++)
//		{
//			if (~dp[j][pr])
//			{
//				dp[j+1][nw]=max(dp[j+1][nw],dp[j][pr]+c[i].a[2]);
//				dp[j][nw]=max(dp[j][nw],dp[j][pr]+max(c[i].a[1],c[i].a[3]));
//			}
//		}
//	}
//	ans=max(dp[n/2][nw],ans);
//	
//	for (int i=0;i<=n;i++) dp[i][0]=dp[i][1]=-1;
//	dp[0][0]=0,nw=0,pr=1;
//	for (int i=1;i<=n;i++)
//	{
//		swap(nw,pr);
//		for (int j=0;j<=n;j++)
//		{
//			if (~dp[j][pr])
//			{
//				dp[j+1][nw]=max(dp[j+1][nw],dp[j][pr]+c[i].a[3]);
//				dp[j][nw]=max(dp[j][nw],dp[j][pr]+max(c[i].a[1],c[i].a[2]));
//			}
//		}
//	}
//	ans=max(dp[n/2][nw],ans);
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	for (int i=1;i<=T;i++) solve();
	return 0;
}
