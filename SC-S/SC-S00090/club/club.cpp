#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3]; 
struct node
{
	int p;
	int c;
	int w;
	friend bool operator<(node xx,node yy)
	{
		return xx.w>yy.w;
	}
}bc[N]; 
struct node1
{
	int p;
	int w;
	friend bool operator<(node1 xx,node1 yy)
	{
		if(xx.w==yy.w) return xx.p>yy.p; 
		return xx.w<yy.w;
	}
};
set<node1> s[4];
int last[N];
int tot=0;
int t,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(;t;t--)
	{
		tot=0;
		//memset(a,0,sizeof(a));
		memset(last,0,sizeof(last));
		for(int i=1;i<=3;i++) s[i].clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
				bc[++tot]={i,j,a[i][j]};
			} 
		sort(bc+1,bc+1+tot);
		long long ans=0;
		for(int i=1;i<=tot;i++)
		{	
			int c=bc[i].c;
			int p=bc[i].p;
			int w=bc[i].w;
			if(s[c].size()<n/2)
			{
				if(!last[p])
				{
					s[c].insert({p,w});
					last[p]=c;
					ans+=w;
				}
			}
			else
			{
				for(set<node1>::iterator it=s[c].begin();it!=s[c].end();it++)
				{
				int tmpp=it->p;
				int tmpw=it->w;
				if(tmpp==p) continue;
				int maxx1=0,id1;
				for(int i=1;i<=3;i++)
				if(i!=last[tmpp] && a[tmpp][i]>maxx1)
				{
					maxx1=a[tmpp][i];
					id1=i;
				}
				int maxx2=0;
				for(int i=1;i<=3;i++)
				if(i!=c && a[p][i]>maxx2) maxx2=a[p][i];
				if(maxx1+w>maxx2+tmpw) 
				{
					s[c].erase(s[c].begin());
					s[c].insert({p,w});
					s[id1].insert({tmpp,maxx1});
					if(last[p]) 
					{
						it=s[last[p]].find({p,a[p][last[p]]});
						s[last[p]].erase(it);
					}
					ans-=a[tmpp][last[tmpp]];
					if(last[p]) ans-=a[p][last[p]];
					ans+=maxx1+w;
					last[p]=c;
					last[tmpp]=id1;
					break; 
				}
				}
				
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/