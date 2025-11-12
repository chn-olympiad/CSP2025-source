#include<iostream>
#include<cstring> 
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int Max=1e4+10;
int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){sum=sum*10+c-'0',c=getchar();}
	return sum*f;
}
struct node
{
	int x,y,val;
}a[Max*10000+1];
int fa[Max],st[15][Max],c[20],n,m;
int cmp(node x,node y)
{
	return x.val<y.val;
}
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long ans=0;
	int k;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].val=read();
	for(int i=1;i<=k;i++)
	{
		int jr=0;
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			st[i][j]=read();
			for(int k=1;k<=j;k++) a[++m].x=j,a[m].y=k,a[m].val=st[i][j]+st[i][k];
		}
	}	
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	int lj=0;
	for(int i=1;i<=m;i++)
	{
		int fx=find(a[i].x),fy=find(a[i].y);
		if(fa[fx]!=fa[fy])
		{
			ans+=a[i].val;
			lj++;
			fa[fx]=fa[fy];
		}
	}
	cout<<ans<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
