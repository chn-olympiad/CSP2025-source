#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define maxn 100005
using namespace std;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c && c<='9'))
	{
		if(c=='-')
		  f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int t,n;
int a[maxn][3];
int cnt[3];

struct p
{
	int id,dis;
	bool operator<(const p x1)const
	{
		return dis>x1.dis;
	}
};

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
        priority_queue<p> q[3];
        cnt[0]=cnt[1]=cnt[2]=0;
		n=read();long long ans=0;
		for(int i=1;i<=n;i++)
		 for(int j=0;j<3;j++)
		    a[i][j]=read();
		for(int i=1;i<=n;i++)
		{
			int x[3]={a[i][0],a[i][1],a[i][2]};
			sort(x,x+3);
		    if((a[i][0]>a[i][1]||a[i][0]==a[i][1]) && (a[i][0]>a[i][2]||a[i][0]==a[i][2]))
		       ++cnt[0],q[0].push((p){i,x[2]-x[1]});
		    else
		    if((a[i][1]>a[i][0]||a[i][1]==a[i][0]) && (a[i][1]>a[i][2]||a[i][1]==a[i][2]))
		       ++cnt[1],q[1].push((p){i,x[2]-x[1]});
		    else
		       ++cnt[2],q[2].push((p){i,x[2]-x[1]});
		    ans+=x[2];
		}
		int s=0;
		if(cnt[1]>n/2)
		  s=1;
		if(cnt[2]>n/2)
		  s=2;
		for(int i=1;i<=cnt[s]-n/2;i++)
		{
		   ans-=q[s].top().dis;
		   //printf("%d ",q[s].top().id);
		   q[s].pop();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
