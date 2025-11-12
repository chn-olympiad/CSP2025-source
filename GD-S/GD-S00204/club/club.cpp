#include<bits/stdc++.h>
using namespace std;
int read()
{
	int tmp=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		tmp=(tmp<<1)+(tmp<<3)+c-'0';
		c=getchar();
	}
	return tmp*f;
}
int T;
int n;
int a[1000001][5];
int mx[1000001][5];
int sum[11];
struct MIKU
{
	int p;
	int now;
};
struct cmp
{
	bool operator()(struct MIKU &u,struct MIKU &v)
	{
		return a[u.p][mx[u.p][u.now]]-a[u.p][mx[u.p][u.now+1]]<a[v.p][mx[v.p][v.now]]-a[v.p][mx[v.p][v.now+1]];
	}
};
priority_queue<MIKU,vector<MIKU>,cmp> q;
int ans;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		sum[1]=sum[2]=sum[3]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			mx[i][1]=mx[i][2]=mx[i][3]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>=a[i][mx[i][1]])
				{
					mx[i][3]=mx[i][2];
					mx[i][2]=mx[i][1];
					mx[i][1]=j;
				}
				else if(a[i][j]>=a[i][mx[i][2]])
				{
					mx[i][3]=mx[i][2];
					mx[i][2]=j;
				}
				else if(a[i][j]>=a[i][mx[i][3]])
				{
					mx[i][3]=j;
				}
			}
		}
		/*for(int i=1;i<=n;i++)
		{
			cout<<mx[i][1]<<" "<<mx[i][2]<<" "<<mx[i][3]<<endl;
		}*/
		for(int i=1;i<=n;i++)
		{
			struct MIKU tmp;
			tmp.p=i;
			tmp.now=1;
			q.push(tmp);
		}
		while(q.empty()!=1)
		{
			struct MIKU cur=q.top();
			q.pop();
			if(sum[mx[cur.p][cur.now]]==n/2)
			{
				q.push(MIKU{cur.p,cur.now+1});
			}
			else
			{
				sum[mx[cur.p][cur.now]]++;
				ans+=a[cur.p][mx[cur.p][cur.now]];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
