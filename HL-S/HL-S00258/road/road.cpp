#include <bits/stdc++.h>
using namespace std;
int n,m,t;
	int x,y,z;
	int fa[100010];
int c; 

struct node{
	int to,next;
	int a,b,c;
	} a[100010];
int pre[100010],k=0;
int jieguo;
bool cmp(node x,node y)
{
	return x.c>y.c;
}
//void add(int )
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

cin>>n>>m>>t;
for(int i=1;i<=m;i++)
{
	cin>>x>>y>>z;
	k++;
	a[k].a=x;
	a[k].b=y;
	a[k].c=z;
	
}
for(int i=1;i<=t;i++)
{
	cin>>c;
	for(int j=1;j<=n;j++)
	{
		cin>>x;
		a[++k]={n+1,j,x};
		sort(a+1,a+k,cmp);
		k=unique(a+1,a+k+1)-a-1;
	}
	n+=t;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
	int s=a[i].a,e=a[i].b,mm=a[i].c;
	jieguo=s+e+mm;
	}
	
	}
	cout<<jieguo;
	

	return 0;
	fclose(stdin);
	fclose(stdout);
} 
