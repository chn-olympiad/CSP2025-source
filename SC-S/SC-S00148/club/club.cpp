#include<bits/stdc++.h>
using namespace std;
#define p pair<int,int>
#define f first
#define s second
struct node
{
	int aclub;
	int bclub;
	int cclub;
	int maxnum;
	int minn;
	int middle;
	int middlenum;
	int minnum;
}stu[100005];
int t,n,club[4],ans;
priority_queue<p> pq;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int kkk=1;kkk<=t;kkk++)
	{
		ans=club[1]=club[2]=club[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>stu[i].aclub>>stu[i].bclub>>stu[i].cclub;
		for(int i=1;i<=n;i++)
		{
			p d;
			int maxn,minn,ac=stu[i].aclub,bc=stu[i].bclub,cc=stu[i].cclub,middle;
			if(ac>=bc&&ac>=cc)maxn=ac,stu[i].maxnum=1;
			else if(bc>=ac&&bc>=cc)maxn=bc,stu[i].maxnum=2;
			else maxn=cc,stu[i].maxnum=3;
			if(ac<=bc&&ac<=cc)minn=ac,stu[i].minnum=1;
			else if(cc<=ac&&cc<=bc&&stu[i].maxnum!=3)minn=cc,stu[i].minnum=3;
			else minn=bc,stu[i].minnum=2;
			if(ac!=bc&&bc!=cc&&cc!=ac)
			{
				if(ac!=maxn&&ac!=minn)middle=ac,stu[i].middlenum=1;
				if(bc!=maxn&&bc!=minn)middle=bc,stu[i].middlenum=2;
				if(cc!=maxn&&cc!=minn)middle=cc,stu[i].middlenum=3;
			}
			else
			{
				if(stu[i].maxnum!=1&&stu[i].minnum!=1)middle=ac,stu[i].middlenum=1;
				if(stu[i].maxnum!=2&&stu[i].minnum!=2)middle=bc,stu[i].middlenum=2;
				if(stu[i].maxnum!=3&&stu[i].minnum!=3)middle=cc,stu[i].middlenum=3;
			}
			stu[i].middle=middle;
			stu[i].minn=minn;
			d.f=maxn-middle;
			d.s=i;
			pq.push(d);
		}
		while(!pq.empty())
		{
			p d=pq.top();
			pq.pop();
			int want=stu[d.s].maxnum;
			if(club[want]==n/2)
			{
				p e;
				e.f=stu[d.s].middle-stu[d.s].minn;
				e.s=d.s;
				stu[d.s].maxnum=stu[d.s].middlenum;
				pq.push(e);
				continue;
			}
			club[want]++;
			ans+=(want==1)?stu[d.s].aclub:(want==2)?stu[d.s].bclub:stu[d.s].cclub;
		}
		cout<<ans<<'\n';
	}
	return 0;
}