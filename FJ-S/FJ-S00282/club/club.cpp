#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
struct p
{
	int a,b,c,maxx;
}x[N];
int ans[N],final=0;
int suma=0,sumb=0,sumc=0;
priority_queue<pair<int,int>>qa;
priority_queue<pair<int,int>>qb;
priority_queue<pair<int,int>>qc;
int max(int q,int r)
{
	if(q>r)
	{
		return q;
	}
	else return r;
}
void dfs(int now)
{
	if(now==n+1)
	{
		int cnt1=0,cnt2=0,cnt3=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(ans[i]==1)
			{
				sum+=x[i].a;
				cnt1++;
			}
			else if(ans[i]==2)
			{
				sum+=x[i].b;
				cnt2++;
			}
			else
			{
				sum+=x[i].c;
				cnt3++;
			}
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2)
		{
			final=max(final,sum);
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		ans[now]=i;
		dfs(now+1);
	}
}
int cmp1(p q,p r)
{
	return q.a>r.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int flagc=0,flagb=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
			x[i].maxx=max(x[i].a,max(x[i].b,x[i].c));
			if(x[i].c!=0)
			{
				flagc=1;
			}
			if(x[i].b!=0)
			{
				flagb=1;
			}
		}
		if(n<=10)
		{
			dfs(1);
			printf("%d\n",final);
		}
		else if(flagb==0&&flagc==0&&n<=20000)
		{
			sort(x+1,x+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				final+=x[i].a;
			}
			printf("%d\n",final);
		}
//		else if(flagc==0)
//		{
//			
//		}
		else
		{
			
			for(int i=1;i<=n;i++)
			{
				if(x[i].maxx==x[i].a)
				{
					if(qa.size()<(n/2))
					{
						qa.push({-x[i].maxx+max(x[i].b,x[i].c),i});
					}
					else
					{
						auto k=qa.top();
						if(k.first+x[i].maxx>max(x[i].b,x[i].c))
						{
							qa.pop();
							qa.push({-x[i].maxx+max(x[i].b,x[i].c),i});
							if(x[k.second].b>x[k.second].c)
							{
								qb.push(k);
							}
							else
							{
								qc.push(k);
							}
						}
						else
						{
							if(x[i].b>x[i].c)
							{
								qb.push({-x[i].maxx+max(x[i].a,x[i].c),i});
							}
							else
							{
								qc.push({-x[i].maxx+max(x[i].a,x[i].c),i});
							}
						}
					}
				}
				else if(x[i].maxx==x[i].b)
				{
					if(qb.size()<(n/2))
					{
						qb.push({-x[i].maxx+max(x[i].a,x[i].c),i});
					}
					else
					{
						auto k=qb.top();
						if(k.first+x[i].maxx>max(x[i].a,x[i].c))
						{
							qb.pop();
							qb.push({-x[i].maxx+max(x[i].a,x[i].c),i});
							if(x[k.second].a>x[k.second].c)
							{
								qa.push(k);
							}
							else
							{
								qc.push(k);
							}
						}
						else
						{
							if(x[i].a>x[i].c)
							{
								qa.push({-x[i].maxx+max(x[i].b,x[i].c),i});
							}
							else
							{
								qc.push({-x[i].maxx+max(x[i].a,x[i].b),i});
							}
						}
					}
				}
				else
				{
					if(qc.size()<(n/2))
					{
						qc.push({-x[i].maxx+max(x[i].a,x[i].b),i});
					}
					else
					{
						auto k=qc.top();
						if(k.first+x[i].maxx>max(x[i].a,x[i].b))
						{
							qc.pop();
							qc.push({-x[i].maxx+max(x[i].a,x[i].b),i});
							if(x[k.second].a>x[k.second].b)
							{
								qa.push(k);
							}
							else
							{
								qb.push(k);
							}
						}
						else
						{
							if(x[i].a>x[i].b)
							{
								qa.push({-x[i].maxx+max(x[i].b,x[i].c),i});
							}
							else
							{
								qb.push({-x[i].maxx+max(x[i].a,x[i].c),i});
							}
						}
					}
				}
			}
			while(qa.size()>=1)
			{
				suma+=x[qa.top().second].a;
				qa.pop();
			}
			while(qb.size()>=1)
			{
				sumb+=x[qb.top().second].b;
				qb.pop();
			}
			while(qc.size()>=1)
			{
				sumc+=x[qc.top().second].c;
				qc.pop();
			}
			printf("%d\n",suma+sumb+sumc);
		}
		final=0;
		suma=sumb=sumc=0;
	}
	return 0;
}
