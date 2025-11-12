#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge{
	int u,v,dis;
}e[1000001];
long long n,m,k,i=1,j,l,u,v,dis,c,num=0,ans=0,sum1=0,a[10001][10001],b[10001],f[10001];
bool cmp(Edge x,Edge y){
	return x.dis<y.dis;
}
int cha(int x)
{
	if(x!=f[x])
	return f[x]=cha(f[x]);
	else
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		a[i][j]=2147483647;
	}
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>dis;
		a[u][v]=dis;
		a[v][u]=dis;
	}
	for(i=1;i<=k;i++)
	{
		cin>>c;
		for(j=1;j<=n;j++)
		{
			cin>>b[j];
			b[j]+=c;
		}
		for(j=1;j<=n;j++)
		{
			for(l=j+1;l<=n;l++)
			{
				a[j][l]=min(a[j][l],b[j]+b[l]-c);
				a[l][j]=a[j][l];
			}
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			e[++num].u=i;
			e[num].v=j;
			e[num].dis=a[i][j];
		}
	}
	sort(e,e+num+1,cmp);
	for(i=1;i<=n;i++)
	f[i]=i;
	for(i=1;i<=num&&sum1!=m;i++)
	{
		int x=e[i].u,y=e[i].v;
		if(cha(x)!=cha(y))
		{
			f[cha(x)]=cha(y);
			sum1++;
			ans+=e[i].dis;
		}
	}
	cout<<ans;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

