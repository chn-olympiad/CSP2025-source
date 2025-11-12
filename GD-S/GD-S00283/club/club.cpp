#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,a[N][5],ans,b[N],tot,t1,t2,t3;
bool f1,f2,vis[N];
int read()
{
	int w=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') w=(w<<3)+(w<<1)+c-'0',c=getchar();
	return w*f;
}
void dfs(int t,int x,int y,int z,int sum)
{
	if(t>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(x+1<=n/2) dfs(t+1,x+1,y,z,sum+a[t][1]);
	if(y+1<=n/2) dfs(t+1,x,y+1,z,sum+a[t][2]);
	if(z+1<=n/2) dfs(t+1,x,y,z+1,sum+a[t][3]);
}
struct node
{
	int w,num,com;
}t[N];
bool cmp(node a,node b)
{
	return a.w>b.w;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();ans=0;tot=0;
		for(int i=1;i<=n;i++)
		{
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			if(a[i][2]!=0) f1=1; 
			if(a[i][3]!=0) f2=1; 
		}
		if(n<=30)
		{
			ans=0;
			dfs(1,0,0,0,0);
			printf("%lld\n",ans);
			continue;
		}
		if(f1==0&&f2==0)
		{
			for(int i=1;i<=n;i++) b[i]=-a[i][1];
			sort(b+1,b+n+1);
			for(int i=1;i<=n/2;i++) ans+=-b[i];
			printf("%lld\n",ans);
			continue;
		}
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
		{
			t[++tot].w=a[i][1];t[tot].num=i;t[tot].com=1ll;
			t[++tot].w=a[i][2];t[tot].num=i;t[tot].com=2ll;
			t[++tot].w=a[i][3];t[tot].num=i;t[tot].com=3ll;
		}
		sort(t+1,t+tot+1,cmp);
		t1=t2=t3=0;
		for(int i=1;i<=tot;i++)
		{
			if(vis[t[i].num]) continue;
			if(t[i].com==1)
			{
				if(t1==n/2) continue;
				ans+=t[i].w;
			}
			if(t[i].com==2)
			{
				if(t2==n/2) continue;
				ans+=t[i].w;
			}
			if(t[i].com==3)
			{
				if(t3==n/2) continue;
				ans+=t[i].w;
			}
			vis[t[i].num]=1;
		}
		printf("%lld\n",ans);
	}
}

