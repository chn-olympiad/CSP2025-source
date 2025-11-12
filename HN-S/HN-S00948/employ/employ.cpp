#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
inline int read(){int x=0;bool b=0;signed c=getchar();while(c<48||c>57)b=c==45,c=getchar();while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();return b?-x:x;}
inline void write(int x,signed c){if(!x){putchar(48),putchar(c);return;}if(x<0)x=-x,putchar(45);signed i=0,a[32];while(x)a[++i]=x%10^48,x/=10;while(i)putchar(a[i--]);putchar(c);}
int n,m,c[20];
bool b[20];
char a[20];
int dfs(int k,int now)
{
	if(n-k+1+now<m)
		return 0;
	if(k>n&&now>=m)
		return 1;
	int s=0;
	for(int i=1;i<=n;i++)
		if(!b[i])
			if(a[k]==49&&c[i]>k-now-1)
				b[i]=1,s=(s+dfs(k+1,now+1))%mod,b[i]=0;
			else
				b[i]=1,s=(s+dfs(k+1,now))%mod,b[i]=0;
	return s;
}
signed main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read(),scanf("%s",a+1);
	for(int i=1;i<=n;i++)
		c[i]=read();
	write(dfs(1,0),10);
	return 0;
}
