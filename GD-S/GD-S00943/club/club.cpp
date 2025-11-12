#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][3],tt[3]={2,1,0},ans;
struct stu
{
	int a,b,c,val,i;
	bool operator<(stu d)const{return val>d.val;}
};
priority_queue<stu>q[3];
struct stu2
{
	int a,b,c,val;
	bool operator<(stu2 d)const{return val<d.val;}
};
priority_queue<stu2>q2[3];
int solveab()
{
	int res=0;
	for(int i=1;i<=n;i++)q[a[i][0]-a[i][1]>0?0:1].push({a[i][0],a[i][1],a[i][2],a[i][0]-a[i][1],i});
	while(!q[0].empty())
	{
		q2[0].push({q[0].top().a,q[0].top().b,q[0].top().c,q[0].top().c-q[0].top().a});
		q[0].pop();
	}
	while(!q[1].empty())
	{
		q2[1].push({q[1].top().a,q[1].top().b,q[1].top().c,q[1].top().c-q[1].top().b});
		q[1].pop();
	}
	while(q2[2].size()<(n>>1))
	{
		if((q2[0].empty()||q2[0].top().val<0)&&(q2[1].empty()||q2[1].top().val<0))break;
		if(q2[1].empty()||(!q2[0].empty()&&q2[0].top().val>=q2[1].top().val))
		{
			q2[2].push(q2[0].top());
			q2[0].pop();
		}
		else
		{
			q2[2].push(q2[1].top());
			q2[1].pop();
		}
	}
	while(!q2[0].empty())
	{
		q[0].push({q2[0].top().a,q2[0].top().b,q2[0].top().c,q2[0].top().a-q2[0].top().b});
		q2[0].pop();
	}
	while(!q2[1].empty())
	{
		q[1].push({q2[1].top().a,q2[1].top().b,q2[1].top().c,q2[1].top().b-q2[1].top().a});
		q2[1].pop();
	}
	while(q[0].size()>(n>>1))
	{
		if(q[0].top().a>=q[0].top().c&&q2[2].size()<(n>>1)||q[1].size()>=(n>>1))
		{
			q2[2].push({q[0].top().a,q[0].top().b,q[0].top().c,0});
			q[0].pop();
		}
		else
		{
			q[1].push(q[0].top());
			q[0].pop();
		}
	}
	while(q[1].size()>(n>>1))
	{
		if(q[1].top().a>=q[1].top().c&&q2[1].size()<(n>>1)||q[0].size()>=(n>>1))
		{
			q2[2].push({q[1].top().a,q[1].top().b,q[1].top().c,0});
			q[1].pop();
		}
		else
		{
			q[0].push(q[1].top());
			q[1].pop();
		}
	}
	while(!q[0].empty())
	{
		res+=q[0].top().a;
		q[0].pop();
	}
	while(!q[1].empty())
	{
		res+=q[1].top().b;
		q[1].pop();
	}
	while(!q2[2].empty())
	{
		res+=q2[2].top().c;
		q2[2].pop();
	}
	return res;
}
int solveac()
{
	int res=0;
	for(int i=1;i<=n;i++)q[a[i][0]-a[i][2]>0?0:2].push({a[i][0],a[i][1],a[i][2],a[i][0]-a[i][2],i});
	while(!q[0].empty())
	{
		q2[0].push({q[0].top().a,q[0].top().b,q[0].top().c,q[0].top().b-q[0].top().a});
		q[0].pop();
	}
	while(!q[2].empty())
	{
		q2[2].push({q[2].top().a,q[2].top().b,q[2].top().c,q[2].top().b-q[2].top().c});
		q[2].pop();
	}
	while(q2[1].size()<(n>>1))
	{
		if((q2[0].empty()||q2[0].top().val<0)&&(q2[2].empty()||q2[2].top().val<0))break;
		if(q2[2].empty()||(!q2[0].empty()&&q2[0].top().val>=q2[2].top().val))
		{
			q2[1].push(q2[0].top());
			q2[0].pop();
		}
		else
		{
			q2[1].push(q2[2].top());
			q2[2].pop();
		}
	}
	while(!q2[0].empty())
	{
		q[0].push({q2[0].top().a,q2[0].top().b,q2[0].top().c,q2[0].top().a-q2[0].top().c});
		q2[0].pop();
	}
	while(!q2[2].empty())
	{
		q[2].push({q2[2].top().a,q2[2].top().b,q2[2].top().c,q2[2].top().c-q2[2].top().a});
		q2[2].pop();
	}
	while(q[0].size()>(n>>1))
	{
		if(q[0].top().a>=q[0].top().c&&q2[1].size()<(n>>1)||q[2].size()>=(n>>1))
		{
			q2[1].push({q[0].top().a,q[0].top().b,q[0].top().c,0});
			q[0].pop();
		}
		else
		{
			q[2].push(q[0].top());
			q[0].pop();
		}
	}
	while(q[2].size()>(n>>1))
	{
		if(q[2].top().a>=q[2].top().c&&q2[1].size()<(n>>1)||q[0].size()>=(n>>1))
		{
			q2[1].push({q[2].top().a,q[2].top().b,q[2].top().c,0});
			q[2].pop();
		}
		else
		{
			q[0].push(q[2].top());
			q[2].pop();
		}
	}
	while(!q[0].empty())
	{
		res+=q[0].top().a;
		q[0].pop();
	}
	while(!q2[1].empty())
	{
		res+=q2[1].top().b;
		q2[1].pop();
	}
	while(!q[2].empty())
	{
		res+=q[2].top().c;
		q[2].pop();
	}
	return res;
}
int solvebc()
{
	int res=0;
	for(int i=1;i<=n;i++)q[a[i][1]-a[i][2]>0?1:2].push({a[i][0],a[i][1],a[i][2],a[i][1]-a[i][2],i});
	while(!q[1].empty())
	{
		q2[1].push({q[1].top().a,q[1].top().b,q[1].top().c,q[1].top().a-q[1].top().b});
		q[1].pop();
	}
	while(!q[2].empty())
	{
		q2[2].push({q[2].top().a,q[2].top().b,q[2].top().c,q[2].top().a-q[2].top().c});
		q[2].pop();
	}
	while(q2[0].size()<(n>>1))
	{
		if((q2[1].empty()||q2[1].top().val<0)&&(q2[2].empty()||q2[2].top().val<0))break;
		if(q2[2].empty()||(!q2[1].empty()&&q2[1].top().val>=q2[2].top().val))
		{
			q2[0].push(q2[1].top());
			q2[1].pop();
		}
		else
		{
			q2[0].push(q2[2].top());
			q2[2].pop();
		}
	}
	while(!q2[1].empty())
	{
		q[1].push({q2[1].top().a,q2[1].top().b,q2[1].top().c,q2[1].top().b-q2[1].top().c});
		q2[1].pop();
	}
	while(!q2[2].empty())
	{
		q[2].push({q2[2].top().a,q2[2].top().b,q2[2].top().c,q2[2].top().c-q2[2].top().b});
		q2[2].pop();
	}
	while(q[1].size()>(n>>1))
	{
		if(q[1].top().a>=q[1].top().c&&q2[0].size()<(n>>1)||q[2].size()>=(n>>1))
		{
			q2[0].push({q[1].top().a,q[1].top().b,q[1].top().c,0});
			q[1].pop();
		}
		else
		{
			q[2].push(q[1].top());
			q[1].pop();
		}
	}
	while(q[2].size()>(n>>1))
	{
		if(q[2].top().a>=q[2].top().c&&q2[0].size()<(n>>1)||q[1].size()>=(n>>1))
		{
			q2[0].push({q[2].top().a,q[2].top().b,q[2].top().c,0});
			q[2].pop();
		}
		else
		{
			q[1].push(q[2].top());
			q[2].pop();
		}
	}
	while(!q2[0].empty())
	{
		res+=q2[0].top().a;
		q2[0].pop();
	}
	while(!q[1].empty())
	{
		res+=q[1].top().b;
		q[1].pop();
	}
	while(!q[2].empty())
	{
		res+=q[2].top().c;
		q[2].pop();
	}
	return res;
}
namespace brute
{
	int f[201][201][201];
	int solve()
	{
		int res=0;
		for(int i=0;i<=200;i++)for(int j=0;j<=200;j++)for(int k=0;k<=200;k++)f[i][j][k]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(i,(n>>1));j++)
			{
				for(int k=0;k<=min(i-j,(n>>1));k++)
				{
					int l=i-j-k;
					if(l>(n>>1))continue;
					if(j>0)f[i][j][k]=max(f[i-1][j-1][k]+a[i][0],f[i][j][k]);
					if(k>0)f[i][j][k]=max(f[i-1][j][k-1]+a[i][1],f[i][j][k]);
					if(l>0)f[i][j][k]=max(f[i-1][j][k]+a[i][2],f[i][j][k]);
					if(i==n)res=max(res,f[i][j][k]);
				}
			}
		}
		return res;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		if(n<=200)printf("%d\n",brute::solve());
		else printf("%d\n",max({solveab(),solveac(),solvebc()}));
	}
	return 0;
}
