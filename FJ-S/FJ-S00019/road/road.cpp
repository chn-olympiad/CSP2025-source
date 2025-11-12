#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4;
const int M=1e6+1e5;
const int inf=0x7fffffff;
int n,nn,m,mm,k;
int c[M+5];
int ans=inf;
struct node
{
	int u,v,w,use;
}a[M+5];
node aa[M+5];
int fa[N+5];
//vector<node>to[N+5];
bool bk[M+5];
//bool use[N+5];
bool visit[M+5];
bool cmp(node xx,node yy)
{
	return xx.w<yy.w;
}
int find(int x)
{
	if(x==fa[x])
		return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int kruscal()
{
	int sum=0;
	int lt=0;
	for(int i=1;i<=n;i++)
		fa[i]=i,visit[i]=0;
	for(int i=1;i<=m;i++)
		aa[i].u=a[i].u,aa[i].v=a[i].v,aa[i].w=a[i].w,aa[i].use=1;
	for(int i=1;i<=k;i++)
		if(bk[i]==0) //不可用 
		{
			for(int j=1;j<=nn;j++)
				aa[mm+(i-1)*nn+j].use=0; //标记 
			sum+=c[i];
		}
	sort(aa+1,aa+m+1,cmp);
//	cout<<"use:";
//	for(int i=1;i<=m;i++)
//		cout<<aa[i].use<<" ";
//	cout<<"\n";		
//	cout<<"father:"<<"\n";
//	for(int i=1;i<=n;i++)
//		cout<<fa[i]<<" ";
//	cout<<"\n";
//	cout<<"firstsum:"<<sum<<"\n";
	for(int i=1;i<=m;i++)
	{
		if(!aa[i].use) continue; //不可用
		int fau=find(aa[i].u),fav=find(aa[i].v); 
//		cout<<fau<<' '<<fav<<"\n";
		if(fau!=fav)
		{
			fa[fau]=fav;
//			cout<<"visit:"<<visit[aa[i].u]<<" "<<visit[aa[i].v]<<<<"\n";
			if(aa[i].u<=nn && !visit[aa[i].u]) visit[aa[i].u]=1,lt++;
			if(aa[i].v<=nn && !visit[aa[i].v]) visit[aa[i].v]=1,lt++;
//			cout<<"choose:"<<aa[i].u<<" "<<aa[i].v<<" "<<lt<<"\n";
			sum+=aa[i].w; 
			if(lt==nn)
				return sum;
		}
		if(sum>=ans)
			return inf;
	}
//	cout<<sum<<" "<<lt<<"\n";
	if(lt==nn)
		return sum;
	return inf;
	//开始找答案 
}
void dfs(int now)
{
	if(now>=k+1)
	{
//		for(int i=1;i<=k;i++)
//			cout<<bk[i]<<' ';
//		cout<<"\n";
		ans=min(ans,kruscal());
		return ;
	}
	bk[now]=1;
	dfs(now+1);
	bk[now]=0;
	dfs(now+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	mm=m,nn=n;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	bool flag;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) flag=false;
		for(int j=1;j<=n;j++)
		{
			m++;
			cin>>a[m].w;
			a[m].u=j,a[m].v=n+i;
			if(a[m].w!=0) flag=false;
		}
	}
	if(flag)
	{
		for(int i=1;i<=k;i++)
			bk[i]=1;
		cout<<kruscal();
		return 0;
	}
	if(k==0)
	{
		cout<<0<<"\n";
		return 0;
	}	
	n=n+k;
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}
