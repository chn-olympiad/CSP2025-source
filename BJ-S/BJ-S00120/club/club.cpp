#include<stdio.h>
#include<algorithm>
using namespace std;
const int NR=1e5+5;
int a[NR][3];
int b[NR];
int c[NR];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		int n;scanf("%d",&n);
		int ct[3]={};
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",a[i]+0,a[i]+1,a[i]+2);
			int t=0;
			for(int j=1;j<=2;++j) if(a[i][j]>a[i][t]) t=j;
			++ct[t];sum+=a[i][t];
			b[i]=t;
		}
		bool fl=0;
		int o;
		for(int i=0;i<3;++i) if(ct[i]*2>n) fl=1,o=i;
		int m=0;
		if(fl)
		{
			for(int i=1;i<=n;++i)
			{
				if(b[i]==o)
				{
					int u=1e9;
					for(int j=0;j<3;++j) if(j!=b[i]) u=min(u,a[i][b[i]]-a[i][j]);
					c[++m]=u;
				}
			}
		sort(c+1,c+m+1);
		//puts("aaa");
		for(int i=1;i<=ct[o]-n/2;++i) sum-=c[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}