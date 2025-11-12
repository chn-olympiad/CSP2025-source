#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m;
struct node
{
	int v,id;
}a[N];
bool cmp(node i,node j)
{
	return i.v>j.v;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i].v),a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,tot=1;
	while(x<=n&&y<=m)
	{
		if(a[tot].id==1)
		{
			printf("%d %d\n",y,x);
			return 0;
		}
		int tx,ty;
		if(y&1)
		{
			tx=x+1,ty=y;
			if(tx>n) tx=n,ty=y+1;
		}
		else
		{
			tx=x-1,ty=y;
			if(tx<1) tx=1,ty=y+1;
		}
		x=tx,y=ty,tot++;
	}
	return 0;
}