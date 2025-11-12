#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
struct node{
	int p,q,r;
}a[3*N];
int detect[3];
int v[3*N];
int t,n;
int sum;
bool cmp(node a,node b)
{
	return a.q>b.q;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		detect[1]=detect[2]=detect[3]=0;
		memset(v,0,sizeof(v));
		scanf("%d",&n);
		int cnt=1;
		for(int i=1;i<=n;i++)
		{
			int d,e,f;
			scanf("%d%d%d",&d,&e,&f);
		 a[cnt].p=i,a[cnt].q=d,a[cnt].r=1;
			a[cnt+1].p=i,a[cnt+1].q=e,a[cnt+1].r=2;
			a[cnt+2].p=i,a[cnt+2].q=f,a[cnt+1].r=3;
			cnt+=3;
		}
		sort(a+1,a+3*n+1,cmp);
		for(int i=1;i<=n*3;i++)
			if(!v[a[i].p]&&detect[a[i].r]+1<=(n/2))
			{
				sum+=a[i].q;
				v[a[i].p]=1;
				detect[a[i].r]++;
			}
		printf("%d\n",sum);
	}
	return 0;
}