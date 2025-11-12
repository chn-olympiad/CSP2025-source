#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m;
int a[100005],b[100005];
int f[19][1<<18];
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		while(c!='0'&&c!='1') c=getchar();
		a[i]=c-'0';
	}
	for(int i=1;i<=n;i++) b[i]=read();
	f[0][0]=1;
	for(int c=1;c<=n;c++)
		for(int s=0;s<(1<<n);s++)
		{
			if(__builtin_popcount(s)!=c) continue;
			for(int j=1;j<=n;j++)
				if(s&(1<<j-1)) 
					for(int i=0;i<c;i++)
					{
						int w=(a[c]==0||b[j]<=i);
						f[i+w][s]=(f[i+w][s]+f[i][s^(1<<j-1)])%mod;
					}
		}
	int ans=0;
	for(int i=0;i<=n-m;i++) ans=(ans+f[i][(1<<n)-1])%mod;
	write(ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
