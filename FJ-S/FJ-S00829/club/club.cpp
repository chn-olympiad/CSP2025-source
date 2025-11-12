#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int T,n,a[N][4],cnt[4],ans;
int mx1[N],mx2[N];
struct node
{
	int id,cost;
	bool operator <(const node &X)const
	{
		return cost<X.cost;
	}
}b[N];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=3;i++)cnt[i]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			mx1[i]=mx2[i]=0;
			for(int j=1;j<=3;j++)
			{
				a[i][j]=read();
				if(a[i][j]>=a[i][mx1[i]])mx2[i]=mx1[i],mx1[i]=j;
				else if(a[i][j]>=a[i][mx2[i]])mx2[i]=j;
			}
			++cnt[mx1[i]],ans+=a[i][mx1[i]];
		}
		int tmp=0;
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]>n/2)
			{
				tmp=i;
				break;
			}
		}
		if(!tmp)
		{
			printf("%d\n",ans);
			continue;
		}
		int now=0;
		for(int i=1;i<=n;i++)
		{
			if(mx1[i]==tmp)b[++now].id=i,b[now].cost=a[i][mx1[i]]-a[i][mx2[i]];
		}
		sort(b+1,b+now+1);
		for(int i=1;i<=cnt[tmp]-n/2;i++)ans-=b[i].cost;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
