#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5],T,n,op[100005],ans,ci[100005][4];
int h[100005][4][4][4];
pair<int,int> d[100005][4];
bool vis[100005],vis2[4][100005];
vector<int>b[5],c;
priority_queue<pair<int,pair<int,int > > >q;
void dfs(int x,int a,int b,int c,int res)
{
	if(a>n/2||b>n/2||c>n/2)return;
	if(h[x][a][b][c]>=res&&res!=0)return;
	h[x][a][b][c]=res;
	ans=max(ans,res);
	if(x>n)
	{
		return;
	}
	dfs(x+1,a+1,b,c,res+ci[x][1]);
	dfs(x+1,a,b+1,c,res+ci[x][2]);
	dfs(x+1,a,b,c+1,res+ci[x][3]);
}
int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
void write(int x)
{
	if(x<0)putchar('-');
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("data.in","r",stdin);
	scanf("%lld",&T);
	while(T--)
	{
		while(!q.empty())q.pop();
		ans=0;
		memset(op,0,sizeof(op));
		memset(h,0,sizeof(h)); 
		n=read();
		for(int i=1;i<=n;i++)
		{
			int a=read(),b=read(),c=read();
			ci[i][1]=a,ci[i][2]=b,ci[i][3]=c;
			d[i][1]={a,1},d[i][2]={b,2},d[i][3]={c,3};
			if(d[i][1].first<d[i][2].first)swap(d[i][1],d[i][2]);
			if(d[i][3].first>d[i][1].first)swap(d[i][3],d[i][1]);
			if(d[i][3].first>d[i][2].first)swap(d[i][3],d[i][2]);
			q.push({a,{i,1}});
			q.push({b,{i,2}});
			q.push({c,{i,3}});
		}
		if(n<=200)
		{
			dfs(1,0,0,0,0);
			write(ans),puts("");
			continue;
		}
		memset(vis2,0,sizeof(vis2));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=3;i++)b[i].clear();
		ans=0;
		a[1]=a[2]=a[3]=0;
		while(!q.empty())
		{
			int id=q.top().second.second,x=q.top().second.first,g=q.top().first;
			q.pop();
			if(vis[x])
			{
				continue;
			}
			if(a[id]==n/2)
			{
				bool f=0;
				int mx=0,K=0;
				int l=b[id].size();
				c.clear();
				for(int i=0;i<l;i++)c.push_back(b[id][i]);
				for(int i=0;i<l;i++)
				{
					if(vis2[id][i])continue;
					int y=c[i];	
					if(op[y]+1>3)continue;
					int res=ans;
					res-=d[y][op[y]].first;
					if(a[d[y][op[y]+1].second]==n/2)res+=d[y][op[y]+2].first;
					else res+=d[y][op[y]+1].first;
					res+=g;
					if(res<=ans)continue;
					if(mx<=res)
					{
						mx=res;
						K=i;
					}
					f=1;
				}
				if(!f)continue;
				for(int i=K;i<=K;i++)
				{
					int y=c[i];	
					if(a[d[y][op[y]+1].second]==n/2)a[d[y][op[y]+2].second]++,b[d[y][op[y]+2].second].push_back(y),op[y]+=2;
					else a[d[y][op[y]+1].second]++,b[d[y][op[y]+1].second].push_back(y),op[y]++;
					a[id]--;
					vis2[id][i]=1;
				}
				ans=mx-g;
			}
			a[id]++;
			b[id].push_back(x),op[x]++;
			vis[x]=1;
			ans+=g;
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				for(int j=1;j<=3;j++)
				{
					if(a[d[i][j].second]!=n/2)ans+=d[i][j].first;
				}
			}
		}
		write(ans),puts("");
	}
	return 0;
}/*
447450
417649
473417
443896
484387




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


1
30
10424 1888 2199
17649 15804 14198
10138 18538 13467
6761 3083 2293
15041 10863 4222
14340 5758 4300
19996 18929 18297
10926 3304 2176
7141 10829 10956
13607 4376 14108
16686 9725 6258
4434 18794 4926
11129 10938 790
8722 4648 9466
8433 9585 14771
14115 7600 2137
13059 4853 4038
16361 10577 6964
11071 2792 4531
19225 16563 12240
4933 7500 11108
13470 7273 3969
19927 15477 7010
13889 8913 284
16346 8745 3469
4832 9878 2776
11723 6399 3415
13453 19859 13711
10335 7892 6192
19584 11583 14062

*/
