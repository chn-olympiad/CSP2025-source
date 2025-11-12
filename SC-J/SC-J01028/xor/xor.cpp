#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e6+10,inf=1e18,mod=1e9+7;
inline int read()
{
	int k=0,f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
int n,k,a[maxn],pre[maxn],f[maxn],lst[(1<<20)+10];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read(),pre[i]=(pre[i-1]^a[i]);
	for(int i=0;i<=(1<<20)-1;i++) lst[i]=-1;
	lst[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(lst[pre[i]^k]!=-1) f[i]=max(f[i-1],f[lst[pre[i]^k]]+1);
		lst[pre[i]]=i;
	}
	cout<<f[n]<<'\n';
	return 0;
}
