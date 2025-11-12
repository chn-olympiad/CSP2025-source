#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read()
{
	int x=0,r=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') r=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*r;
}

const int mo=998244353;

string ud;
int d[505];
int n,m;

int dp[19][(1<<18)+5];

int s[(1<<18)+5];

int cmp(int x,int y)
{
	return __builtin_popcount(x)<__builtin_popcount(y);
}

void work1()
{
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++) s[i]=i;
	sort(s,s+(1<<n),cmp);
	for(int i=0;i<(1<<n);i++)
	{
		int u=__builtin_popcount(s[i]);
		//cout<<u<<' '<<s[i]<<endl;
		/*
		if(u<=5)
		{
			for(int j=0;j<=u;j++) cout<<dp[j][s[i]]<<endl;
		}
		* */
		for(int j=0;j<=u;j++)
		{
			if(!dp[j][s[i]]) continue;
			for(int k=0;k<n;k++)
			{
				if(((s[i]>>k)&1)==0)
				{
					if(d[k]>u-j&&ud[u]=='1')
					{
						dp[j+1][s[i]|(1<<k)]=(dp[j+1][s[i]|(1<<k)]+dp[j][s[i]])%mo;
					}
					else
					{
						dp[j][s[i]|(1<<k)]=(dp[j][s[i]|(1<<k)]+dp[j][s[i]])%mo;
					}
				}
			}
		}
	}
	int ans=0;
	int w=(1<<n)-1;
	for(int i=m;i<=n;i++) ans=(ans+dp[i][w])%mo;
	printf("%lld\n",ans);
}

int qpow(int t,int x)
{
	int ans=1;
	while(x)
	{
		if(x%2) ans=ans*t%mo;
		t=t*t%mo;
		x/=2;
	}
	return ans;
}

int ni(int t)
{
	return qpow(t,mo-2);
}

int pre[505];
int nxt[505];
int dpre[505];
int ds[505];
int pre0[505];

int gp[505][505];

int C(int x,int y)
{
	if(x<y) return 0;
	return pre[x]*nxt[y]%mo*nxt[x-y]%mo;
}

void work2()
{
	pre[0]=1;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]*i%mo;
	nxt[n]=ni(pre[n]);
	for(int i=n-1;i>=0;i--) nxt[i]=nxt[i+1]*(i+1)%mo;
	for(int i=0;i<n;i++)
	{
		ds[d[i]]++;
		pre0[i]=pre0[i-1]+(ud[i]=='0');
	}
	for(int i=1;i<=n;i++)
	{
		dpre[i]=ds[i]+dpre[i-1];
	}
	int ans=0;
	gp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=0;j<=pre0[i-1];j++)
		{
			//cout<<j<<endl;
			cnt=(cnt+gp[i-1][j]*C(dpre[n]-dpre[i-1],j)%mo*(dpre[n]-dpre[i-1]-j)%mo);
		}
		//cout<<cnt<<endl;
		if(ud[i-1]!='0') ans=(ans+cnt*pre[n-i]%mo)%mo;
		//cout<<i<<' '<<ans<<endl;
		for(int j=0;j<=pre0[i-2];j++)
		{
			int s=ds[i-1];
			if(ud[i-1]=='0')
			{
				gp[i][j+1]=(gp[i][j+1]+gp[i-1][j])%mo;
			}
			int nw=j+(ud[i-1]=='0');
			for(int l=(ud[i-1]=='0');l<=nw;l++)
			{
				gp[i][nw-l]=(gp[i][nw-l]+gp[i-1][j]*C(s,l)%mo)%mo;
			}
		}
	}
	printf("%lld\n",ans);
}

void work3()
{
	int ans=1;
	for(int i=0;i<n;i++)
	{
		if(d[i]==0) ans=0;
		if(ud[i]=='0') ans=0;
		ans=ans*(i+1)%mo;
	}
	printf("%lld\n",ans);
}

void work()
{
	n=read();
	m=read();
	cin >> ud;
	for(int i=0;i<n;i++) d[i]=read();
	if(m==n) work3();
	else if(n<=18) work1();
	
	else if(m==1) work2();
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
	//T=read();
	while(T--) work();
	return 0;
}
