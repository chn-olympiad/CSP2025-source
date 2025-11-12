#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node
{
	int num,past;
}a[100101][4];
typedef pair<int,int> PII;
priority_queue<PII> p;
bool cmp(node x,node y)
{
	return x.num<y.num||(x.num==y.num&&x.past<y.past);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		int sum[4]={0};
		int ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%lld",&a[i][j].num);
				a[i][j].past=j;
			}
			sort(a[i]+1,a[i]+1+3,cmp);
			ans+=a[i][1].num;
			for(int j=3;j>=1;j--)
				a[i][j].num-=a[i][1].num;
		}
		for(int i=1;i<=n;i++)
			ans+=a[i][2].num;
		for(int i=1;i<=n;i++)
			p.push({a[i][3].num-a[i][2].num,i});
		while(p.size())
		{
			int t=p.top().second;
			if(sum[a[t][3].past]+1<=n/2)
			{
				ans+=p.top().first;
				sum[a[t][3].past]++;
			}
			p.pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
