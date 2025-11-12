#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,mod=998244353;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f; 
}
int n,m,a[510],b[510],ans;
int f[510][510];
char s[510];
bool vis[510];
void dfs(int t)
{
	if(t>n)
	{
		int sum=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||sum>=a[b[i]])++sum;
			else ++num;
		}
		if(num>=m)++ans;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		b[t]=i;vis[i]=1;
		dfs(t+1);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
/*
*/
