#include<bits/stdc++.h>
using namespace std;
const int N=1145141;
struct node{
	int s,id;
}a[N][4];
priority_queue <int> p[4]; 
bool cmp(node c,node d)
{
	return c.s>d.s;
}
int b[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T)
	{
		T--;
		int n;
		long long ans=0;
		for(int i=1;i<=3;i++)
		{
			b[i]=0;
			while(!p[i].empty())
			  p[i].pop();
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1].s,&a[i][2].s,&a[i][3].s);
			a[i][1].id=1;
			a[i][2].id=2;
			a[i][3].id=3;
			sort(a[i]+1,a[i]+1+3,cmp);
			int dj=a[i][1].s-a[i][2].s;
			if(b[a[i][1].id]<n/2)
			{
				b[a[i][1].id]++;
				p[a[i][1].id].push(dj*(-1));
				ans+=a[i][1].s;
			}
			else
			{
				int ndj=p[a[i][1].id].top();
				ndj*=(-1);
				if(ndj<dj)
				{
					ans-=ndj;
					ans+=a[i][1].s;
					p[a[i][1].id].pop();
					p[a[i][1].id].push(dj*(-1));
				}
				else
				{
					ans+=a[i][2].s;
					p[a[i][2].id].push(dj*(-1));
					b[a[i][2].id]++;
				}
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
 } //我要上人类迷惑行为大赏！*114514 
