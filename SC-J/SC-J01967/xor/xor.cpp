#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10,M=2e6+10;
int a[N],f[N];
int s[N];
int h[N],g[M];
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	if(n<=1000)
	{
		f[0]=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=max(f[i],f[i-1]);
			for(int j=1;j<=i;j++)
			{
				if((s[j-1]^s[i])==k) f[i]=max(f[i],f[j-1]+1);
			}
		}
		printf("%d\n",f[n]);
	}
	else
	{
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) h[i]=(k^s[i]);
		memset(g,-1,sizeof(g));
		g[0]=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=max(f[i],f[i-1]);
			if(g[h[i]]!=-1&&g[h[i]]!=i) f[i]=max(f[i],f[g[h[i]]]+1);
			g[s[i]]=i;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}