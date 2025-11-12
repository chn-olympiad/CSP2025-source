#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct Node
{int i;int m;int l;};

bool cmp(const Node& a,const Node& b)
{
	if(a.i==b.i)
	{
		return a.l < b.l;
	}return a.i<b.i;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		Node w[n];
		int ans = 0;
		for(int i = 0;i < n;++i)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b&&a>=c)
			{
				w[i].l = min(a-b,a-c);
				w[i].m = a;
				w[i].i = 0;
			}
			else if(b>=a&&b>=c)
			{
				w[i].l = min(b-a,b-c);
				w[i].m = b;
				w[i].i = 1;
			}
			else
			{
				w[i].l = min(c-b,c-a);
				w[i].m = c;
				w[i].i = 2;
			}
		}
		sort(w,w+n,cmp);
		int num[3] = {0,0,0};
		int cnt[2] = {0,0};
		for(int i = 0;i < n;++i)
		{
			ans+=w[i].m;
			if(w[i].i==1&&w[i-1].i==0)cnt[0] = i;
			if(w[i].i==2&&w[i-1].i==1)cnt[1] = i;
			++num[w[i].i];
		}
		int i = 0;
		while(num[0]>n/2)ans-=w[i].l,++i,--num[0];
		i = cnt[0];
		while(num[1]>n/2)ans-=w[i].l,++i,--num[1];
		i = cnt[1];
		while(num[2]>n/2)ans-=w[i].l,++i,--num[2];
		printf("%d\n",ans);
	}return 0;
}
