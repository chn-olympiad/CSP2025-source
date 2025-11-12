#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAXN=1e4+200,MAXM=3e6;
int p[MAXN];
int n,m,k,tot;
int c[11];
struct node
{
	int f,t,w;
 }way[MAXM];
int findp(int x)
{
	if(p[x]==0)return x;
	else 
	{
		p[x]=findp(p[x]);
		return p[x];
	}
}
void hb(int x,int y)
{
	int px=findp(x);
	int py=findp(y);
	if(px==py)return ;
	else p[px]=py;
}
bool check1(int x,int y)
{
	int px=findp(x);
	int py=findp(y);
//	cout<<px<<' '<<py<<endl;
	return px==py;
}
signed main ()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>way[i].f>>way[i].t>>way[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int pl=m+(i-1)*n+j;
			cin>>way[pl].w;
			way[pl].f=n+i;
			way[pl].t=j;
			//cout<<n+i<<' '<<way[pl].w<<endl;
		}
		
	}
	sort(way+1,way+m+k*n+1,[](const node &a,const node &b)
	{
		return a.w<b.w;
	});
	int tot=0;
	int ans=0;
	int pos=1;
	while(tot<n+k-1&&pos<=m+k*n)
	{
		int f=way[pos].f;
		int t=way[pos].t;
		int w=way[pos].w;
		if(check1(f,t)==0)
		{
			tot+=1;
			ans+=w;
			hb(f,t);	//cout<<f<<' '<<t<<' '<<w<<endl;
		}
	
		
		
		pos++;
	}
	cout<<ans;
	
	return 0;
}
