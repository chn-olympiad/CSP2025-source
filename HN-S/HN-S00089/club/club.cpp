#include <bits/stdc++.h> 
using namespace std;
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
#define _ read<int>()
#define int long long
#define rint register int
#define R register 
template<class T>inline T read()
{
	T r=0,f=1;R char c=gc();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=gc();
	}
	while(isdigit(c)) r=(r<<1)+(r<<3)+(c^48),c=gc();
	return f*r;	
} 
inline void out(rint x)
{
	if(x<0) pc('-'),x=-x;
	if(x<10) pc(x+'0');
	else out(x/10),pc(x%10+'0');
}
const int N=1e5+10,M=110;
int dp[2][M][M][M],n,dpp[2][M][M];
struct oi
{
	int x,y,z;
}a[N];
inline bool cmp(const oi &x,const oi &y)
{
	return max(max(x.x,x.y),x.z)>max(max(y.x,y.y),y.z);
}
inline bool cmp1(const oi &x,const oi &y)
{
	if(x.x!=y.x) return x.x>y.x;
	return max(max(x.x,x.y),x.z)>max(max(y.x,y.y),y.z);
}
inline bool cmp2(const oi &x,const oi &y)
{
	if(x.y!=y.y) return x.y>y.y;
	return max(max(x.x,x.y),x.z)>max(max(y.x,y.y),y.z);
}
inline bool cmp3(const oi&x,const oi &y)
{
	if(x.z!=y.z) return x.z>y.z;
	return max(max(x.x,x.y),x.z)>max(max(y.x,y.y),y.z);
}
inline int js1()
{
	rint xcnt=0,ycnt=0,zcnt=0,ans=0;
	for(rint i=1;i<=n;i++)
	{		
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
		{
			if(xcnt<n/2)
			{
				ans+=a[i].x;
				xcnt++;
			}
			else if((a[i].y>=a[i].z&&ycnt<n/2)||zcnt>=n/2)
			{
				ans+=a[i].y;
				ycnt++;
			}
			else ans+=a[i].z;
		}
		else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) 
		{
			if(ycnt<n/2)
			{
				ans+=a[i].y;
				ycnt++;
			}
			else if((a[i].x>=a[i].z&&xcnt<n/2)||zcnt>=n/2)
			{
				xcnt++;
				ans+=a[i].x;
			}
			else
			{
				zcnt++;
				ans+=a[i].z;
			}
		}
		else ans+=a[i].z,zcnt++;
	}
	return ans;
}
inline int js2()
{
	rint xcnt=0,ycnt=0,zcnt=0,ans=0;
	for(rint i=1;i<=n;i++)
	{		
		if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
		{
			if(ycnt<n/2)
			{
				ans+=a[i].y;
				ycnt++;
			}
			else if((a[i].x>=a[i].z&&xcnt<n/2)||zcnt>=n/2)
			{
				ans+=a[i].x;
				xcnt++;
			}
			else ans+=a[i].z;
		}
		else if(a[i].x>=a[i].y&&a[i].x>=a[i].z) 
		{
			if(xcnt<n/2)
			{
				ans+=a[i].x;
				xcnt++;
			}
			else if((a[i].z>=a[i].y&&zcnt<n/2)||ycnt>=n/2)
			{
				zcnt++;
				ans+=a[i].z;
			}
			else
			{
				ycnt++;
				ans+=a[i].y;
			}
		}
		else ans+=a[i].z,zcnt++;
	}
	return ans;
}
inline int js3()
{
	rint xcnt=0,ycnt=0,zcnt=0,ans=0;
	for(rint i=1;i<=n;i++)
	{		
		if(a[i].z>=a[i].y&&a[i].z>=a[i].x)
		{
			if(zcnt<n/2)
			{
				ans+=a[i].z;
				zcnt++;
			}
			else if((a[i].y>=a[i].z&&ycnt<n/2)||xcnt>=n/2)
			{
				ans+=a[i].y;
				ycnt++;
			}
			else ans+=a[i].x;
		}
		else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) 
		{
			if(ycnt<n/2)
			{
				ans+=a[i].y;
				ycnt++;
			}
			else if((a[i].x>=a[i].z&&xcnt<n/2)||zcnt>=n/2)
			{
				xcnt++;
				ans+=a[i].x;
			}
			else
			{
				zcnt++;
				ans+=a[i].z;
			}
		}
		else ans+=a[i].x,xcnt++;
	}
	return ans;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	rint t=_;
	while(t--)
	{
		n=_;
		bool f=1,ff=1;
		for(rint i=1;i<=n;i++)
		{
			a[i]={_,_,_};
			if(a[i].y||a[i].z) f=0;
			if(a[i].z) ff=0;
		}
		rint ans=0;
		if(f)
		{
			sort(a+1,a+n+1,cmp);
			for(rint i=1;i<=n/2;i++) ans+=a[i].x;
		}
		else if(ff&&n<=210)
		{
			memset(dpp,0,sizeof(dpp));
			for(rint i=1;i<=n;i++)
			{
				for(rint j=0;j<=n/2;j++)
				{
					for(rint k=0;k<=n/2;k++)
					{ 
						if(j+k>n) break;
						dpp[i&1][j][k]=max(dpp[i&1][j][k],dpp[(i-1)&1][j][k]);
						if(j) dpp[i&1][j][k]=max(dpp[i&1][j][k],dpp[(i-1)&1][j-1][k]+a[i].x);
						if(k) dpp[i&1][j][k]=max(dpp[i&1][j][k],dpp[(i-1)&1][j][k-1]+a[i].y);
					} 
				}
			}
			for(rint j=0;j<=n/2;j++)
			{
				for(rint k=0;k<=n/2;k++)
				{
					if(n<k+j) break;
					rint l=n-k-j;
					ans=max(dpp[n&1][j][k],ans);
				}
			}
		}
		else if(n<=100)
		{
			memset(dp,0,sizeof(dp));
			for(rint i=1;i<=n;i++)
			{
				for(rint j=0;j<=n/2;j++)
				{
					for(rint k=0;k<=n/2;k++)
					{ 
						for(rint l=0;l<=n/2;l++)
						{
							if(j+k+l>n) break;
							dp[i&1][j][k][l]=max(dp[i&1][j][k][l],dp[(i-1)&1][j][k][l]);
							if(j) dp[i&1][j][k][l]=max(dp[i&1][j][k][l],dp[(i-1)&1][j-1][k][l]+a[i].x);
							if(k) dp[i&1][j][k][l]=max(dp[i&1][j][k][l],dp[(i-1)&1][j][k-1][l]+a[i].y);
							if(l) dp[i&1][j][k][l]=max(dp[i&1][j][k][l],dp[(i-1)&1][j][k][l-1]+a[i].z);
						}
					} 
				}
			}
			for(rint j=0;j<=n/2;j++)
			{
				for(rint k=0;k<=n/2;k++)
				{
					if(n<k+j) break;
					rint l=n-k-j;
					ans=max(dp[n&1][j][k][l],ans);
				}
			}
		}
		else
		{
			sort(a+1,a+n+1,cmp);
			ans=max(ans,js1());
			sort(a+1,a+n+1,cmp1);
			ans=max(ans,js1());
			sort(a+1,a+n+1,cmp2);
			ans=max(ans,js2());
			sort(a+1,a+n+1,cmp3);
			ans=max(ans,js3()); 
		}
		out(ans);
		pc('\n');
	}
	return 0;
}
