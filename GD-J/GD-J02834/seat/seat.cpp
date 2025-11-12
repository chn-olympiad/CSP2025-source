#include<algorithm>
#include<cstdio>
int n,m;
struct str
{
	int num,res;
}a[101];
auto cmp=[](str x,str y){return x.res>y.res;};
void dfs(int x,int y,int no,int dir)
{
	if(a[no].num==1)
	{
		printf("%d %d",y,x);
		return;
	}else
	{
		if(x+dir>n)
		{
			dfs(x,y+1,no+1,-1);
		}else if(x+dir<=0)
		{
			dfs(x,y+1,no+1,1);
		}else dfs(x+dir,y,no+1,dir);
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].res);
		a[i].num=i;
	}
	std::sort(a+1,a+(n*m)+1,cmp);
	dfs(1,1,1,1);
}
