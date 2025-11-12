#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int from[2000006],to[2000006],how=0;//存图 
int fa[20004];//并查集 
int size[20004],td[11],flag=0;
int fin(int a)
{
	int f=fa[a];
	int past[20004],p=0;
	past[p]=a;
	while(f!=fa[f])
	{
		past[++p]=f;
		f=fa[f];
	}
	for(int i=0;i<=p;i++)fa[past[i]]=f;
	return fa[a];
}
bool uni(int a,int b)//代表非跳点 
{
	int x=fin(a),y=fin(b);
	if(x==y)return false;
	else
	{
		fa[x]=y;
		if(a>n)td[a-n]=b;
		if(b>n)td[b-n]=a;
		size[y]+=size[x];
		int o=size[y];
		for(int i=1;i<=k;i++)if(fin(td[i])==y)o--;
		if(o>=n)flag=1;
		return true;
	}
}
//跳点
int c[11],a[11][10004];
int sy[11][10004];//记录tiaodian边编号 
int c2[11];
//存边小根堆q 
struct edge
{
	int num,we;
	bool operator< (const edge &b) const
	{
		return this->we>b.we;
	}
};
priority_queue<edge> q;
int vis[1000006];
long long ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	//存图 
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		how++;
		from[how]=u;to[how]=v;
		edge e;e.num=how;e.we=w;q.push(e);
	}
	//跳点n+1~n+k
	for(int i=1;i<=k;i++)
	{
		int A=0;
		td[i]=n+i;
		cin>>c[i];A+=c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];A+=a[i][j];
			how++;
			from[how]=n+i;to[how]=j;
			sy[i][j]=how;
		    edge e;e.num=how;e.we=a[i][j]+c[i];
			q.push(e);
		}
		if(A==0)
		{
			cout<<0;return 0;
		}
    }
	//合并
	for(int i=1;i<=n+k;i++){fa[i]=i;size[i]=1;}
	while(!q.empty())
	{
		edge e=q.top();q.pop();
		if(vis[e.num]==1)continue;
		if(uni(from[e.num],to[e.num]))
		{
			ans+=e.we;
			if(e.num>m)//一条跳点边 
			{
				int ui=e.num-m;
				if(ui%n==0)ui/=n;
				else ui=ui/n+1;//第几个跳点 
				c2[ui]++;
			}
			//cout<<e.num<<' '<<e.we<<'\n';
		}
		vis[e.num]=1;
		if(flag==1)break;
	}
	//for(int i=1;i<=n+k;i++)cout<<fin(i)<<' ';cout<<'\n';
	for(int i=1;i<=k;i++)
	{
		if(c2[i]>0)
		{
			c2[i]--;
			for(int j=1;j<=c2[i];j++)ans-=c[i];
		}
	}
	cout<<ans;
	return 0;
}
