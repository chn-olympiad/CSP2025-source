#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+1e5+10; 
int n,m,k,u,v,w,c[15],a[15][N],f[N];
long long ans;
struct stu
{
	int x,y,z;
}ed[M];
int in()
{
	int w=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		w=w*10+c-'0';
		c=getchar(); 
	}
	return f*w;
}
bool cmp(stu x,stu y)
{
	return x.z<y.z;
}
int zu(int x)
{
	if(f[x]==x) return x;
	f[x]=zu(f[x]);
	return f[x];
}
void Kruskal()
{
	sort(ed+1,ed+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int uu=ed[i].x,vv=ed[i].y,ww=ed[i].z;
		int aa=zu(uu),bb=zu(vv);
		if(aa==bb) continue;
		f[aa]=bb; 
		ans+=ed[i].z;
	}
}
bool check()
{
	for(int i=1;i<=k;i++) 
	{
		if(c[i]!=0) return false;
		for(int j=1;j<=n;j++) 
			if(a[i][j]!=0) return false;
	}
	return true;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) 
	{
		u=in();v=in();w=in();
		if(u>v) swap(u,v);
		ed[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=in();
		for(int j=1;j<=n;j++) a[i][j]=in();
	}
	if(k&&check()) 
	{
		cout<<0;
		return 0;
	}
	Kruskal();
	cout<<ans;
	return 0;
 } 
 /*
 4 4 0
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 */
