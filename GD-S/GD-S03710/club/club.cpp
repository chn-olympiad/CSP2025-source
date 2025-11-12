#include<bits/stdc++.h>
#define ll long long
#define N 100010
#define ull unsigned long long
using namespace std;
inline long long read(){
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int a[N][4],p[N],num[N],mx=-1,n,c[N];
struct ljfyyds{
	int c,id;
}b[N];
int cmp(ljfyyds a,ljfyyds b)
{
	return a.c>b.c;
}
void dfs(int x)
{
	if(x==n+1)
	{
		int ans=0;
		for(int i=1;i<=n;i++) ans+=a[i][p[i]];
		mx=max(mx,ans);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(num[i]+1<=n/2) p[x]=i,num[i]++;
		else continue;
		dfs(x+1);
		num[i]--;
	}
}
void solve()
{
	memset(p,0,sizeof(p));
	memset(num,0,sizeof(num));
	mx=-1;
	n=read();
	int f=1,op=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			a[i][j]=read();
		}
		if(a[i][2]!=0||a[i][3]!=0) f=0;
		if(a[i][3]!=0) op=1;
	}
	if(f==1)
	{
		for(int i=1;i<=n;i++) c[i]=a[i][1];
		sort(c+1,c+n+1);
		int sum=0;
		for(int i=n/2+1;i<=n;i++) sum+=c[i];
		printf("%lld\n",sum);
		return;
	}
	if(op==0)
	{
		int sum=0;
		for(int i=1;i<=n;i++) b[i]={a[i][1]-a[i][2],i};
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n/2;i++) sum+=a[b[i].id][1];
		for(int i=n/2+1;i<=n;i++) sum+=a[b[i].id][2];
		printf("%lld\n",sum);
		return; 
	}
	dfs(1);
	printf("%lld\n",mx);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	t=read();
	while(t--) solve();
	return 0;
}


