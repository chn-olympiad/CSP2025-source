#include <bits/stdc++.h>
using namespace std;

const int N=2e6+10;

int club[3],n;
long long sum=0;
bool af[N];

struct node
{
	int a,num,c;
}a[N*3];

bool cmp(node n1,node n2)
{
	return n1.a>n2.a;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		memset(af,0,sizeof(af));
		scanf("%d",&n);
		int s=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				s++;
				scanf("%d",&a[s].a);
				a[s].c=j,a[s].num=i;
			}
		}
		sort(a+1,a+3*n+1,cmp);
		int member=0;
		for(int i=1;i<=n*3;i++)
		{
			if(club[a[i].c]<=n/2 && !af[a[i].num])
			{
				club[a[i].c]++;
				af[a[i].num]=1;
				sum+=a[i].a;
				member++;
			}
			if(member==n) break;
		}
		printf("%lld\n",sum);
	}

	return 0;
}

