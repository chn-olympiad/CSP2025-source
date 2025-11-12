#include<cstdio>
#include<queue>
int max(const int &a,const int &b,const int &c)
{
	return (a>c?(a>b?a:b):(c>b?c:b));
}
int min(const int &a,const int &b,const int &c)
{
	return (a<c?(a<b?a:b):(c<b?c:b));
}
int med(const int &a,const int &b,const int &c)
{
	return a+b+c-min(a,b,c)-max(a,b,c);
}
struct Node
{
	int _0,_1,_2;
	bool operator<(const Node& b)const
	{
		return max(_0,_1,_2)-med(_0,_1,_2)>max(b._0,b._1,b._2)-med(b._0,b._1,b._2);
	}
	int big()const
	{
		return max(_0,_1,_2);
	}
	int small()const
	{
		return med(_0,_1,_2);
	}
};
Node stu[100001];
std::priority_queue<Node>q0,q1,q2;
int p[3];
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
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&stu[i]._0,&stu[i]._1,&stu[i]._2);
			int maxn=stu[i].big();
			ans+=maxn;
			if(maxn==stu[i]._0)
			{
				p[0]++;
				q0.push(stu[i]);
				continue;
			}
			else if(maxn==stu[i]._1)
			{
				p[1]++;
				q1.push(stu[i]);
				continue;
			}
			else
			{
				p[2]++;
				q2.push(stu[i]);
				continue;
			}
		}
		Node a;
		while(p[0]>n/2)
		{
			a=q0.top();
			q0.pop();
			p[0]--;
			ans-=a.big()-a.small();
		}
		while(p[1]>n/2)
		{
			a=q1.top();
			q1.pop();
			p[1]--;
			ans-=a.big()-a.small();
		}
		while(p[2]>n/2)
		{
			a=q2.top();
			q2.pop();
			p[2]--;
			ans-=a.big()-a.small();
		}
		printf("%lld\n",ans);
		p[0]=p[1]=p[2]=0;
		while(!q0.empty())q0.pop();
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
	}
	return 0;
}
