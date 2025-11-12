#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ff
{
	int a,b,c,maxx,bel;
}f[100010];
int dp[202][202][202]={0};
int cmp(ff aa,ff bb)
{return aa.maxx>bb.maxx;}
int q[3]={0},s=0;
int add(int idx)
{
	q[f[idx].bel]++;
	return f[idx].maxx;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T,n,m;
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%lld%lld%lld",&f[i].a,&f[i].b,&f[i].c);
		if(n<=201)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<=i;j++)
				{
					for(int k=0;k<=i-j;k++)//dp[i-j-k][j][k]
					{
						dp[i-j-k+1][j][k]=max(dp[i-j-k+1][j][k],dp[i-j-k][j][k]+f[i].a);
						dp[i-j-k][j+1][k]=max(dp[i-j-k][j+1][k],dp[i-j-k][j][k]+f[i].b);
						dp[i-j-k][j][k+1]=max(dp[i-j-k][j][k+1],dp[i-j-k][j][k]+f[i].c);
					}
				}
			}
			int maxxx=0;
			for(int i=0;i<=n/2;i++)
				for(int j=0;j<=n/2;j++)
					if(n-i-j<=n/2)
						maxxx=max(maxxx,dp[i][j][n-i-j]);
			cout<<maxxx<<endl;
		}
		else
		{
			for(int i=0;i<n;i++)
				f[i].maxx=0;
			for(int i=0;i<n;i++)
				f[i].maxx=max(f[i].a,max(f[i].b,f[i].c));
			sort(f,f+n,cmp);
			int fflag=0;
			for(int i=0;i<n;i++)
			{
				if(f[i].a==f[i].maxx)
					f[i].bel=0;
				if(f[i].b==f[i].maxx)
					f[i].bel=1;
				if(f[i].c==f[i].maxx)
					f[i].bel=2;
			}
			for(int i=0;i<n;i++)
				if(f[i].b==0 && f[i].c==0)
					fflag++;
			if(fflag==n)
			{
				s=0;
				for(int i=0;i<n/2;i++)
					s+=f[i].maxx;
				cout<<s<<endl;
				continue;
			}
			q[0]=0,q[1]=0,q[2]=0,s=0;
			for(int i=0;i<n;i++)
			{
				if(q[f[i].bel]<n/2)
					s+=add(i);
				else
				{
					if(f[i].maxx==f[i].a)
					{
						int flag=0;
						f[i].maxx=max(f[i].b,f[i].c);
						if(f[i].b>f[i].c)
							f[i].bel=1,flag=2;
						else
							f[i].bel=2,flag=1;
						if(q[f[i].bel]>=n/2)
							f[i].bel=flag;
						s+=add(i);
					}
					if(f[i].maxx==f[i].b)
					{
						int flag=0;
						f[i].maxx=max(f[i].a,f[i].c);
						if(f[i].a>f[i].c)
							f[i].bel=0,flag=2;
						else
							f[i].bel=2,flag=0;
						if(q[f[i].bel]>=n/2)
							f[i].bel=flag;
						s+=add(i);
					}
					if(f[i].maxx==f[i].c)
					{
						int flag=0;
						f[i].maxx=max(f[i].b,f[i].a);
						if(f[i].b>f[i].a)
							f[i].bel=1,flag=0;
						else
							f[i].bel=0,flag=1;
						if(q[f[i].bel]>=n/2)
							f[i].bel=flag;
						s+=add(i);
					}
				}
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
