#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct rd{
	int w,v;
	/*const bool &operator < : (const rd &_x,const rd &_y)
{
	if(_x.w==_y.w)
	return _x.v<_y.v;
	return _x.w<_y.w;
	}*/
};
bool cmp(rd x,rd y)
{
	if(x.w==y.w)
		return x.v<y.v;
	return x.w<y.w;
}
int c[11],tag[10021],l=1,r=1;
rd ar[1100001];
//priority_queue<rd> pq;
vector<rd> p[10021];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		rd rr;
		int u,v;
		scanf("%d %d %d",&u,&v,&rr.w);
		rr.v=v;
		p[u].push_back(rr);
		rr.v=u;
		p[v].push_back(rr);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			rd rr;
			scanf("%d",&rr.w);
			rr.v=j;
			p[n+i].push_back(rr);
			rr.v=n+i;
			p[j].push_back(rr);
		}
	}
	int a=1;
	tag[1]=1;
	for(int i=0;i<p[1].size();i++)
	{
		if(p[1][i].v>n)
		{
			rd rr=p[1][i];
			rr.w+=c[p[1][i].v-n];
			//pq.push(rr);
			ar[r]=rr;
			r++;
		}
		else
		{
			//pq.push(p[1][1]);
			ar[r]=p[1][i];
			r++;
		}
	}
	long long ans=0;
	while(a<n)
	{
		sort(ar+l,ar+r,cmp);
		while(tag[ar[l].v])
			l++;
		//while(tag[pq.top().v])
		//	pq.pop();
		int v=ar[l].v;
		//int v=pq.top().v;
		tag[v]=1;
		if(v>n)
		{
			ans+=ar[l].w;
			//ans+=pq.top().w;
			//printf("%d\n",ar[l].w);
			for(int i=0;i<p[v].size();i++)
			{
				if(tag[p[v][i].v]==0)
				{
					ar[r]=p[v][i];
					r++;
					//pq.push(p[v][i]);
				}
			}
		}
		else
		{
			a++;
			ans+=ar[l].w;
			//ans+=pq.top().w;
			//printf("%d\n",ar[l].w);
			for(int i=0;i<p[v].size();i++)
			{
				if(tag[p[v][i].v]==0)
				{
					rd rr=p[v][i];
					if(v>n&&tag[v]==0)
						rr.w+=c[v-n];
					//pq.push(rr);
					ar[r]=rr;
					r++;
				}
			}
		}
		//pq.pop();
		l++;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//freopen
//T2 road
//Luogu: WOLFSTAR(1044658)
//CSP-S2025 rp++
//NOIP2025 rp++
//来てくれてありがとう！

//C国还是太城市化了

//谁懂开考之前循环溜了半小时キティ现在还在脑子里响着的救赎感