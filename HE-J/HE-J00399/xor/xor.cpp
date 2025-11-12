#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read();

const int N=5e5+10;

int n,k,a[N],f[1010][1010];

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	int sum1=0,sum0=0;
	for(int i=1; i<=n; i++)
	{
		a[i]=read();
		if(a[i]==1) sum1++;
		if(a[i]==0) sum0++;
	}
	memset(f,-1,sizeof f);
	if(sum1+sum0==n&&sum1==n) printf("%lld",sum1/2);
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				if(i==j) f[i][j]=a[i];
				else
				{
					int ss=a[i];
					for(int p=i+1;p<=j;p++) ss=ss^a[p];
					f[i][j]=ss;
				}
			}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				bool ff=1;
				for(int p=i;p<=j;p++)
					if(a[p]==-1)
					{
						ff=0;
						break;
					}
				if(f[i][j]==k&&ff)
				{
					ans++;
					for(int p=i;p<=j;p++) a[p]=-1;
					i++;
					j=i;
				}
			}
		printf("%lld",ans);
	}
	return 0;
}

inline int read()
{
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

