#include<bits/stdc++.h>
using namespace std;
const int N=10015,M=1000015;
int n,m,k,xb;
int c[15][N];
int d[N];
int fa[M];
int po[N];
struct road{
	int u,v,w;
	int next;
}a[M];
void add(int x,int y,int z)
{
	a[++xb].u=x;
	a[xb].v=y;
	a[xb].w=z;
	a[xb].next=d[x];
	d[x]=xb;
	return;
}
void uadd(int x,int y)
{
	fa[x]=y;
	return;
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=fa[fa[x]];
}
int kru()
{
	queue<int>q;
	q.push(1);
	while(!q.empty())
	{
		int ls=q.front();
		q.pop();
		int ne=d[ls];
		while(a[ne].next!=0)
		{
			int xxx=a[ne].v;
			if(find(xxx)!=1)
			{
				if(po[xxx]>po[ls]+a[ne].w+(xxx>n?c[xxx-n][0]:0))
				{
					po[xxx]=po[ls]+a[ne].w+(xxx>n?c[xxx-n][0]:0);
					q.push(a[ne].v);
					uadd(xxx,ls);
				}
			}
			ne=a[ne].next;
		}
		if(q.size()==1)
			return po[ls];
	}
	return 0;
}
void coutt(){
	for(int i=1;i<=xb;i++)
	{
		if(a[i].u>n)
			cout<<"$ ";
		cout<<i<<" "<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<" "<<a[i].next<<"\n"; 
	}
		
	return;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(po,127,sizeof(po));
	po[1]=0;
	for(int i=1;i<=m;i++)
	{
		int xx,yy,zz;
		cin>>xx>>yy>>zz;
		add(xx,yy,zz);
		add(yy,xx,zz);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i][0];
		for(int j=1;j<=n;j++)
			cin>>c[i][j],add(i+n,j,c[i][j]),add(j,i+n,c[i][j]);
	}
	//coutt();
	
	cout<<kru();
	return 0;
}
/*
   1   1  4  6 0
   10  1  5  1 1
   18  1  6  1 10
   
   3   2  3  7 0
   6   2  4  5 3
   12  2  5  8 6
   20  2  6  3 12
   
   4   3  2  7 0
   8   3  4  4 4
   14  3  5  2 8
   22  3  6  2 14
   
   2   4  1  6 0
   5   4  2  5 2
   7   4  3  4 5
   16  4  5  4 7
   24  4  6  4 16
   
$  9   5  1  1 0
$  11  5  2  8 9
$  13  5  3  2 11
$  15  5  4  4 13

$  17  6  1  1 0
$  19  6  2  3 17
$  21  6  3  2 19
$  23  6  4  4 21
*/
