#include<bits/stdc++.h>
using namespace std;
int a[3][100005];
bool cmp(int x,int y)
{
	return x>y;
}
vector<int> c;
vector<int> d;
int li;
priority_queue<int,vector<int>,greater<int> >qa;
priority_queue<int,vector<int>,greater<int> >qb;
priority_queue<int,vector<int>,greater<int> >qc;
priority_queue<int,vector<int>,greater<int> >qd;
priority_queue<int,vector<int>,greater<int> >qe;
priority_queue<int,vector<int>,greater<int> >qf;
//1:1~2 2:1~3 3:2~1 4:2~3 5:3~1 6:3~2
int aa,ab,ac;
int ll(int i)
{
	if(i==1)
	{
		if(aa==0)
		{
			return 0;
		}
		if(aa==li)
		{
			return qa.top();
		}
		return max(qa.top(),0);
	}
	else if(i==2)
	{
		if(aa==0)
		{
			return 0;
		}
		if(aa==li)
		{
			return qb.top();
		}
		return max(qb.top(),0);
	}
	else if(i==3)
	{
		if(ab==0)
		{
			return 0;
		}
		if(ab==li)
		{
			return qc.top();
		}
		return max(qc.top(),0);
	}
	else if(i==4)
	{
		if(ab==0)
		{
			return 0;
		}
		if(ab==li)
		{
			return qd.top();
		}
		return max(qd.top(),0);
	}
	else if(i==5)
	{
		if(ac==0)
		{
			return 0;
		}
		if(ac==li)
		{
			return qe.top();
		}
		return max(qe.top(),0);
	}
	else
	{
		if(ac==0)
		{
			return 0;
		}
		if(ac==li)
		{
			return qf.top();
		}
		return max(qf.top(),0);
	}
}
int le(int i)
{
	if(i==1)
	{
		if(aa==0)
		{
			return 0;
		}
		return qa.top();
	}
	else if(i==2)
	{
		if(aa==0)
		{
			return 0;
		}
		return qb.top();
	}
	else if(i==3)
	{
		if(ab==0)
		{
			return 0;
		}
		return qc.top();
	}
	else if(i==4)
	{
		if(ab==0)
		{
			return 0;
		}
		return qd.top();
	}
	else if(i==5)
	{
		if(ac==0)
		{
			return 0;
		}
		return qe.top();
	}
	else
	{
		if(ac==0)
		{
			return 0;
		}
		return qf.top();
	}
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
		li=n/2;
		bool ff=true,fff=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%d",&a[j][i]);
				if(j==1&&a[j][i]!=0)
				{
					ff=false;
				}
				else if(j==2&&a[j][i]!=0)
				{
					fff=false;
				}
			}
		}
		if(ff&&fff)
		{
			int ans=0;
			sort(a[0]+1,a[0]+1+n,cmp);
			for(int i=1;i<=li;i++)
			{
				ans+=a[0][i];
			}
			printf("%d\n",ans);
		}
		else if(fff)
		{
			int ans=0;
			for(int i=1;i<=li;i++)
			{
				ans+=a[0][i];
				c.push_back(a[1][i]-a[0][i]);
			}
			for(int i=li+1;i<=n;i++)
			{
				ans+=a[1][i];
				d.push_back(a[0][i]-a[1][i]);
			}
			sort(c.begin(),c.end(),cmp);
			sort(d.begin(),d.end(),cmp);
			for(int i=0;i<=li;i++)
			{
				if(c[i]+d[i]>0)
				{
					ans+=c[i]+d[i];
				}
				else
				{
					break;
				}
			}
			printf("%d\n",ans);
		}
		else
		{
			int ans=0;
			for(int i=1;i<=li;i++)
			{
				ans+=a[0][i];
				qa.push(a[1][i]-a[0][i]);
				qb.push(a[2][i]-a[0][i]);
			}
			for(int i=li+1;i<=n;i++)
			{
				ans+=a[1][i];
				qc.push(a[0][i]-a[1][i]);
				qd.push(a[2][i]-a[1][i]);
			}
			aa=li,ab=li;
			while(1)
			{
				int w1=le(1)+ll(3);
				int w2=le(2)+ll(5);
				int w3=le(3)+ll(1);
				int w4=le(4)+ll(6);
				int w5=le(5)+ll(2);
				int w6=le(6)+ll(4);
				int maxx=0;
				break;
			}
		}
	}
	return 0;
}
