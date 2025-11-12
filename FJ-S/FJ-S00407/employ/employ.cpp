#include<bits/stdc++.h>
#define int long long
#define R read()
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define gc getchar
using namespace std;
int read()
{
	int x=0,f=1;
	char c=gc();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+c-48,c=gc();
	return x*f;
}
void write(int x,char xx)
{
	static int st[35],tot=0;
	if(x<0) putchar('-'),x=-x;
	do {st[++tot]=x%10,x/=10;}
	while(x);
	while(tot) putchar('0'+st[tot--]);
	putchar(xx);
}
#define N 510
#define mod 998244353
int n,m,s[N],c[N],p[N],ans,jc[N];
namespace sub1
{
	void mian()
	{
		for(int i=1;i<=n;i++) p[i]=i;
		do
		{
			int su=0,us=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]==0||su>=c[p[i]]) su++;
				else us++;
			}
			ans+=(us>=m);
		}while(next_permutation(p+1,p+n+1));
		write(ans%mod,'\n');
	}
}
namespace sub2
{
	int f[N],cnt[N],tnc;
	void mian()
	{
		f[0]=1;
		for(int i=1;i<=n;i++) cnt[c[i]]++;
		for(int i=1,num=cnt[0];i<=n;i++)
		{
			num+=cnt[i];
			if(s[i]==0) tnc++,f[i]=f[i-1];
			else f[i]=f[i-1]*(num-(i-tnc-1))%mod;
		}
		write((jc[n]-f[n]*jc[tnc]%mod+mod)%mod,'\n');
	}
}
int op()
{
	char c=gc();
	while(c!='0'&&c!='1') c=gc();
	return c-'0';
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=R,m=R,jc[0]=1;
	int sum=0,mn=n+1;
	for(int i=1;i<=n;i++) s[i]=op(),sum+=s[i],jc[i]=jc[i-1]*i%mod;
	for(int i=1;i<=n;i++) c[i]=R,mn=min(mn,c[i]);
	if(sum<m) puts("0");
	else if(n<=10) sub1::mian();
	else if(m==n)
	{
		if(mn) write(jc[n],'\n');
		else puts("0");
	}
	else if(sum==n&&mn) write(jc[n],'\n');
	else if(m==1) sub2::mian();
	else sub1::mian();
	return 0;
}

