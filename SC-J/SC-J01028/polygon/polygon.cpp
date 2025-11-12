#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e3+10,inf=1e18,mod=998244353;
inline int read()
{
	int k=0,f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
int n,a[maxn],f[maxn],g[maxn],ans; 
void add(int &x,int y)
{
	((x+=y)>=mod)?x-=mod:x; 
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=maxn-9;j>=0;j--)
		{
			if(j+a[i]>5000) add(g[5001],f[j]);
			else add(g[j+a[i]],f[j]);
			if(j>a[i]) add(ans,f[j]);
		}
		for(int j=maxn-9;j>=0;j--) add(f[j],g[j]),g[j]=0;
	}
	cout<<ans<<"\n";
	return 0;
}
