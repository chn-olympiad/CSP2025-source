#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define il inline 

const int maxna=1e4+5;
const int maxnb=1e6+5;
const int maxnc=1e3+5;
const int maxnd=1e9;

typedef pair<int,pair<int,int>> pii;
int n, m, k, ans, v, u, w, kk, cnt;
int a[maxnb], b[15][maxna], dis[maxnc][maxnc];
int fa[maxna];
priority_queue<pii,vector<pii>,greater<pii>> q;

il int read()
{
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return num*f;
}

il int find(int a)
{
	if(fa[a]==a) return a;
	return fa[a]=find(fa[a]);
}

il void uni(int a,int b)
{
	int f_a=fa[a], f_b=fa[b];
	if(f_a!=f_b) fa[a]=f_b;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	if(k==0)
	{
		int l;
		for(int i=1;i<=m;i++)
		{
			l=read();
			l=read();
			a[i]=read();
		}
		sort(a+1,a+m+1);
		for(int i=1;i<=n-1;i++) ans+=a[i];
		cout << ans << endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++) dis[i][j]=1e9;
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		u=read();v=read();w=read();
		if(u<v) dis[u][v]=min(dis[u][v],w);
		else dis[v][u]=min(dis[v][u],w);
		
	}
	for(int i=1;i<=k;i++)
	{
		kk=read();
		for(int j=1;j<=n;j++) b[i][j]=read();
		for(int j=1;j<=n;j++)
		{
			for(int o=j+1;o<=n;o++)
			{
				dis[j][o]=dis[o][j]=min(dis[j][o],b[i][o]+b[i][j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++) cout << dis[i][j] << " ";
		cout << endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			pii p;
			p.first=dis[i][j];
			p.second={i,j};
			q.push(p);
		}
	}
	while(cnt<n)
	{
		pii pp=q.top();
		int pa, pb;
		pa=pp.second.first;pb=pp.second.second;
		if(find(pa)==find(pb)) continue;
		ans+=pp.first;
		uni(pa,pb);
		cnt++;
		q.pop();
	}
	cout << ans;
	return 0;
}
