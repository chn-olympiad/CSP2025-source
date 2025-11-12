#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,tot=1,head[11005],c[15][10005],C[15];
bool vis[105];
struct node
{
	int to,nxt,v,from,i;
}arr[5000005];
bool cmp(node a,node b)
{
	return a.v<b.v;
}
void edge(int x,int y,int z,int op)
{
	arr[tot]={y,head[x],z,x,op};
	head[x]=tot++;
}
int fa[100005];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int ans=0,res=LLONG_MAX;
void A(){
	if(ans>=res)return;
	for(int i=0;i<=n+k+1;i++)fa[i]=i;
	for(int i=1;i<=tot;i++)
	{
		if(!vis[arr[i].i])continue;
		int x=arr[i].to,y=arr[i].from;
		int fx=find(x),fy=find(y);
		if(fx==fy)continue;
		fa[fx]=fy;
		ans+=arr[i].v;
		if(ans>=res)return;
	}
	if(res>ans)res=ans;
}
int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
void write(int x)
{
	if(x<0)putchar('-');
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		u=read(),v=read(),w=read();
		edge(u,v,w,0);
//		edge(v,u,w,0);
	}
	vis[0]=1;
	for(int i=1;i<=k;i++)
	{
		C[i]=read();
		for(int j=1;j<=n;j++)
			c[i][j]=read(),edge(i+n,j,c[i][j],i);//,edge(j,i+n,c[i][j],i);
	}
	sort(arr+1,arr+1+tot,cmp);
	if(k==0)A(),write(res);
	else
	{
		for(int i=0;i<(1ll<<k);i++)
		{
			ans=0;
			for(int j=k;j>=1;j--)vis[j]=0;
			vis[0]=1;
			for(int j=k;j>=1;j--)
				if((i>>(j-1))&1)ans+=C[j],vis[j]=1;
			A();
		}
		write(res);
	}
	return 0;
}
