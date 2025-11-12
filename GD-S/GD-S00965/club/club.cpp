#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double

int read()
{
	int x=0,f=1;
	char ch=' ';
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

void prt(int x)
{
	if (x==0)
	{
		putchar('0');
		return;
	}
	if (x<0) putchar('-'),x=-x;
	int stac[20],top=0;
	while (x)
	{
		stac[++top]=x%10;
		x/=10; 
	}
	while (top)
	{
		putchar(stac[top--]^48);
	}
	return;
}

const int maxn=1e5+10;

int t,n;
struct Member
{
	int a,b,c;
}m[maxn];

int ans,cb[maxn],cb_ans[maxn];
int dp[2][5001][5001];
bool SubA;

void BF(int i,int n1,int n2,int n3,int sna)
{
	if (i==n+1)
	{
		if (ans<sna)
		{
			for (int j=1;j<=n;j++) cb_ans[j]=cb[j];
			ans=sna;
		}
		return;
	}
	if (n1+1<=n/2)
	{
		cb[i]=1;
		BF(i+1,n1+1,n2,n3,sna+m[i].a);
	}
	if (n2+1<=n/2)
	{
		cb[i]=2;
		BF(i+1,n1,n2+1,n3,sna+m[i].b);
	}
	if (n3+1<=n/2)
	{
		cb[i]=3;
		BF(i+1,n1,n2,n3+1,sna+m[i].c);
	}
}

bool cmpA(Member x,Member y)
{
	return x.a>y.a;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	t=read();
	while (t--)
	{
		n=read();ans=0;
		SubA=true;
		for (int i=1;i<=n;i++)
		{
			m[i].a=read();
			m[i].b=read();
			m[i].c=read();
			cb[i]=cb_ans[i]=0;
			if (m[i].b!=0||m[i].c!=0) SubA=false;
		}
		if (SubA)
		{
			sort(m+1,m+n+1,cmpA);
			for (int i=1;i<=n/2;i++)
			{
				ans+=m[i].a;
			}
		}
		else if (n<=10)
		{
			BF(1,0,0,0,0);
//			for (int i=1;i<=n;i++)
//			{
//				cout<<cb_ans[i]<<" ";
//			}
		}
		else
		{
			for (int x=0;x<=n/2;x++)
			{
				for (int y=0;y<=n/2;y++)
				{
					dp[0][x][y]=dp[1][x][y]=0;
				}
			}
			for (int i=1;i<=n;i++)
			{
				for (int x=0;x<=i&&x<=n/2;x++)
				{
					for (int y=0;y<=i-x&&y<=n/2;y++)
					{
						if (i-x-y>n/2) continue;
						int I=i&1;
						if (x)
						{
							dp[I][x][y]=max(dp[I][x][y],dp[!I][x-1][y]+m[i].a);
						}
						if (y)
						{
							dp[I][x][y]=max(dp[I][x][y],dp[!I][x][y-1]+m[i].b);
						}
						if (i-x-y)
						{
							dp[I][x][y]=max(dp[I][x][y],dp[!I][x][y]+m[i].c);
						}
					}
				}
			}
			for (int x=0;x<=n/2;x++)
			{
				for (int y=0;y<=n-x&&y<=n/2;y++)
				{
					if (n-x-y>n/2) continue;
					ans=max(ans,dp[n&1][x][y]);
				}
			}
		}
		prt(ans);putchar('\n');	
	}
	
	return 0;
}
