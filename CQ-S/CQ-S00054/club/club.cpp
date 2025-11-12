#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4];
struct node
{
	int x;
	int id;
}p[N][4];
bool cmp(node x,node y)
{
	return x.x>y.x;
}
inline void read(int &ret)
{
	ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
}
struct node2
{
	int w;
	int id;
	int nxt;
	bool operator <(const node2 &oth)const
	{
		return w<oth.w;
	}
};
long long ans=0;
priority_queue<node2 > q[4];
int n;
void insert(int i,int fr)
{
	for(int j=fr;j<=3;j++)
	{
		int id=p[i][j].id;
		int x=p[i][j].x;
		
		if(q[id].size()<n/2)
		{
//			if(i<=2) cout<<i<<" "<<id<<"\n";
			ans=ans+1LL*x;
			q[id].push({p[i][j+1].x-x,i,j});
			break;
		}
		else
		{
			
//			cout<<i<<" "<<id<<" "<<q[id].size()<<"\n";
//			puts("sfd");
			auto t=q[id].top();
//			if(i==4) cout<<j<<" "<<t.w<<"\n";
			if(t.w>p[i][j+1].x-x)
			{
				
//				cout<<i<<" "<<j<<" "<<t.w<<"\n";
				ans=ans-1LL*p[t.id][t.nxt].x;
				ans=ans+1LL*x;
				q[id].pop();
				q[id].push({p[i][j+1].x-x,i,j});
				insert(t.id,t.nxt+1);
				break;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int cas;
	read(cas);
	while(cas--)
	{
		
		read(n);
		for(int i=1;i<=n;i++)
		{
			read(a[i][1]);
			read(a[i][2]);
			read(a[i][3]);
			p[i][1]={a[i][1],1};
			p[i][2]={a[i][2],2};
			p[i][3]={a[i][3],3};
		}
		for(int i=1;i<=3;i++)
		{
			while(q[i].size()) q[i].pop();
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			sort(p[i]+1,p[i]+3+1,cmp);
//			if(i==4) printf("%d ",p[i][1].x);
			insert(i,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

