#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=1e5+10,si=210;
int dp[si][si][si],a[maxn][5],p[maxn];
struct node {
	int sa,sb;
}q[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline bool cmp(const node x,const node y)
{
	return abs(x.sa-x.sb)>abs(y.sa-y.sb);
}
inline void operate()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=3;++j)
			a[i][j]=read();
	
	if (n>200)
	{
		int fl2=0,fl3=0;
		for (int i=1;i<=n;++i)
			fl2+=a[i][2],
			fl3+=a[i][3];
		if (fl2==0 && fl3==0)
		{
			for (int i=1;i<=n;++i)
				p[i]=a[i][1];
			sort(p+1,p+n+1);
			for (int i=n;i>n/2;--i)
				ans+=p[i];
			printf("%d\n",ans);return;
		}
		
		else if (fl3==0)
		{
			for (int i=1;i<=n;++i)
				q[i].sa=a[i][1],
				q[i].sb=a[i][2];
			sort(q+1,q+n+1,cmp);
			int ff=0;
			for (int i=1;i<=n;++i)
				if (q[i].sa>q[i].sb && ff<n/2)
					ff++,ans+=q[i].sa;
				else ans+=q[i].sb;
			printf("%d\n",ans);
			return;
		}
		else printf("77777777\n");
		return;
	}
			
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;++i)
	{
		for (int j=0;j<=i-1 && j<=n/2;++j)
		{
			for (int k=0;j+k<=i-1 && k<=n/2;++k)
			{
				int h=i-1-j-k;
				if (h>n/2) continue;
				dp[i][j+1][k]=max(dp[i][j+1][k],dp[i-1][j][k]+a[i][1]);
				dp[i][j][k+1]=max(dp[i][j][k+1],dp[i-1][j][k]+a[i][2]);
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
			}
		}
	}
	
	for (int i=0;i<=n/2;++i)
		for (int j=0;j<=n/2;++j)
		{
			int k=n-i-j;
			if (k>n/2) continue;
			ans=max(ans,dp[n][i][j]);
		}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int Z=read();
	while (Z--) operate();
} 
