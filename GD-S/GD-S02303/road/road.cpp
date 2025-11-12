#include<bits/stdc++.h>
using namespace std;
struct datay
{
	int x,y,v;
}b[1000005],a[100005],t[15][20005];
int n,m1,m,k,v[15],fa[20005],p,num,h,v1[15],blo;
long long minn,s;
char c=' ';
bool cmp1(datay q,datay w){return q.v<w.v;}
int search(int x)
{
	if(fa[x]!=x)fa[x]=search(fa[x]);
	return fa[x];
}
//void add(int x,int y,int z)
//{
//	x=search(x),y=search(y);
//	if(x!=y)fa[y]=x,s+=z,blo--;
//	return;
//}
int dijah()
{
	h=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')h=h*10+c-'0',c=getchar();
	return h;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y;
	minn=1e15;
	scanf("%d%d%d",&n,&m1,&k),p=(1<<k);
	for(int i=1;i<=m1;i++)b[i].x=dijah(),b[i].y=dijah(),b[i].v=dijah();
	sort(b+1,b+m1+1,cmp1); 
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m1;i++)
	{
		x=search(b[i].x),y=search(b[i].y);
		if(x!=y)fa[y]=x,a[++m]=b[i];
	}
	for(int i=1;i<=k;i++)
	{
		v[i]=dijah();
		for(int j=1;j<=n;j++)t[i][j].v=dijah(),t[i][j].y=j;
		sort(t[i]+1,t[i]+n+1,cmp1);
	}
	for(int i=0;i<p;++i)
	{
		s=m1=num=0,blo=n;
		for(int j=1;j<=k;++j)v1[j]=0;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=k;++j)
			if(i&(1<<(j-1)))s+=v[j],v1[j]=1,blo++;
		for(int j=1;j<=m;++j)
		{
			for(int u=1;u<=k;++u)
				if(v1[u])
				{
					while(v1[u]<=n&&t[u][v1[u]].v<=a[j].v)
					{
						x=search(u+n),y=search(t[u][v1[u]].y);
						if(x!=y)
						{
							fa[y]=x,s+=t[u][v1[u]].v,blo--;
							if(blo==1)break;
						}
						v1[u]++;
					}
					if(blo==1)break;
				}
			x=search(a[j].x),y=search(a[j].y);
			if(x!=y)fa[y]=x,s+=a[j].v,blo--;
			if(blo==1)break;
		}
		minn=min(minn,s);
//		printf("%d:%lld\n",i,s);
	}
	printf("%lld",minn);






  return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
