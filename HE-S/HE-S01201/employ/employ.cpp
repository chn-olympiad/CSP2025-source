#include<bits/stdc++.h>

using namespace std;
const int N=505,md=998244353;
void inline add(int &x,int y)
{
	x+=y;
	if(x>=md) x-=md;
}
void inline del(int &x,int y)
{
	x-=y;
	if(x<0) x+=md;
}
int inline inc(int x,int y)
{
	return x+y-(x+y>=md?md:0);
}
int inline inc1(int x,int y)
{
	return x-y+(x<y?md:0);
}
int n,m,fac[N],ifac[N],f[N][N][N],g[N][N][N],cnt[N],val[N],d[N];
char s[N];
int c(int n,int m)
{
	return 1ll*fac[n]*ifac[m]%md*ifac[n-m]%md;
}
int a(int n,int m)
{
	return 1ll*fac[n]*ifac[n-m]%md;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<=500;i++)
		fac[i]=1ll*i*fac[i-1]%md,ifac[i]=1ll*(md-md/i)*ifac[md%i]%md;
	for(int i=2;i<=500;i++)
		ifac[i]=1ll*ifac[i-1]*ifac[i]%md;
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++) cin>>d[i],cnt[d[i]]++,val[d[i]]++;
	for(int i=n;i>=0;i--) cnt[i]+=cnt[i+1];
	for(int i=0;i<=n-m;i++) f[n][i][0]=1;
	if(m==1)
	{
		int res=1,ans=fac[n],cnt0=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				res=1ll*res*(cnt[0]-cnt[i]-cnt0)%md;
				cnt0++;
			}
		}
		res=1ll*res*fac[n-cnt0]%md;
		cout<<inc1(ans,res);
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||c[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		cout<<fac[n];
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='1')
		{
		//	cout<<i<<endl;
			for(int j=0;j<=n;j++)
			{
				for(int k=n;k>=0;k--)
				{
					if(cnt[j+1]-(n-i-k)>0) 
						add(f[i-1][j][k],1ll*f[i][j][k]*(cnt[j+1]-(n-i-k))%md);
					if(k)
					{
						for(int l=0;l<=val[j+1];l++)
							add(f[i-1][j][k],1ll*c(k-1+l,l)*a(val[j+1],l)%md*f[i][j+1][k+l-1]%md);
					}
				//	g[i][j][k]=inc(g[i][j][k+1],1ll*fac[k]*f[i][j][k]%md);
				}
			}
//			for(int j=0;j<=n;j++)
//			{
//				for(int k=1;k<=n;k++)
//				{
//					add(f[i-1][j][k],1ll*ifac[k-1]*inc1(g[i][j+1][k-1],k+val[j+1]<=n?g[i][j+1][k+val[j+1]]:0)%md);
//				}
//			}

		}
		else
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					for(int l=0;l<=val[j+1];l++)
					{
						if(l+k) add(f[i-1][j][k],1ll*a(val[j+1],l)*c(k+l,l)%md*f[i][j+1][k+l-1]%md);
						if(cnt[j+2]-(n-i-k-l)>0) add(f[i-1][j][k],1ll*(cnt[j+2]-(n-i-k-l))*f[i][j+1][k+l]%md*c(k+l,l)%md*a(val[j+1],l)%md);
					}
				}
			}
		}
//		for(int j=0;j<=n;j++)
//			for(int k=0;k<=n;k++)
//				cout<<i-1<<' '<<j<<' '<<k<<' '<<f[i-1][j][k]<<endl;
			
	}
	cout<<1ll*fac[val[0]]*f[0][0][val[0]]%md;
}
