#include<cstdio>
#include<algorithm>
int T,n,d[3];
struct s
{
	long long a;
	int idx,idx2;
}a[300005];
long long ans=0;
void dfs(int i,int x,int y,int z,long long t)
{
	if(i<=n)
	{
		if(x<(n>>1))dfs(i+1,x+1,y,z,t+a[i*3-2].a);
		if(y<(n>>1))dfs(i+1,x,y+1,z,t+a[i*3-1].a);
		if(z<(n>>1))dfs(i+1,x,y,z+1,t+a[i*3].a);
	}
	else if(ans<t)
	{
		ans=t;
	}
}
bool vis[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(--T>=0)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n*3;++i)
		{
			scanf("%lld",&a[i].a);
			a[i].idx=(i-1)/3+1;
			a[i].idx2=(i-1)%3;
			vis[(i-1)/3+1]=0;
		}
		if(n<=10)
		{
			dfs(1,0,0,0,0);
		}
		else
		{
			std::sort(a+1,a+1+n*3,[](s x,s y){return x.a>y.a;});
			d[0]=d[1]=d[2]=0;
			for(int i=1;i<=n*3;++i)
			{
				if(vis[a[i].idx]==0&&d[a[i].idx2]<(n>>1))
				{
					vis[a[i].idx]=1;
					++d[a[i].idx2];
					ans+=a[i].a;
				}
			}
		}
		printf("%lld",ans);
		if(T)putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}