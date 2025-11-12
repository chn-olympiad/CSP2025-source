#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+10,maxn2=1e1+10,Mod=998244353;
int n,m,ans;
int c[maxn],dp[1<<18][maxn2];
char s[maxn];
int read()
{
	int ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
int add(int x,int y) {return x+y>=Mod?x+y-Mod:x+y;}
void inpu()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) c[i]=read();
}
void deal1()
{
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++)
	{
		int si=0;
		for(int k=1;k<=n;k++) if(i&(1<<(k-1))) si++;
		for(int j=0;j<si;j++)
		{
			for(int k=1;k<=n;k++) if(i&(1<<(k-1)))
			{
				if(s[si]=='0')
				{
					dp[i][j+1]=add(dp[i][j+1],dp[i^(1<<(k-1))][j]);
				}else
				{
					if(c[k]>j) dp[i][j]=add(dp[i][j],dp[i^(1<<(k-1))][j]);
					else dp[i][j+1]=add(dp[i][j+1],dp[i^(1<<(k-1))][j]);
				}
			}
		}
	}
	for(int j=n-m;j>=0;j--) ans=add(ans,dp[(1<<n)-1][j]);
}
void deal2()
{
	for(int i=1;i<=n;i++) if(s[i]=='0') return;
	for(int i=1;i<=n;i++) if(c[i]<1) return;
	ans=1;
	for(int i=1;i<=n;i++) ans=1ll*ans*i%Mod;
}
void solve()
{
	inpu();
	if(n<=18) deal1();
	else if(n==m) deal2();
	printf("%d",ans);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t=1;
	while(t--) solve();
	return 0;
}