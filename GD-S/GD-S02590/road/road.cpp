#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

long long n,m,k;
long long u,v,w; 
long long ans = 0x3f3f3f3f;

struct edge{
	long long u,v,w;
} tmp;

struct IN{
	long long num;
	map<long long,bool> vis;
	long long sum;
	long long cnt;
};

vector<edge> head[10005];

long long num,city[50],kkk;

queue<IN> q;
IN tm1,tm2;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	
	kkk = m;
	
	for(long long i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		
		tmp.u = u,tmp.v = v,tmp.w = w;
		head[u].push_back(tmp);
		tmp.u = v,tmp.v = u;
		head[v].push_back(tmp);
	}
	
	for(long long i = 1; i <= k; i++)
	{
		cin >> city[i];
		++m;
		for(long long j = 1; j <= n; j++)
		{
			cin >> num;
			
			tmp.u = m,tmp.v = j,tmp.w = num;
			head[m].push_back(tmp);
			tmp.u = j,tmp.v = m;
			head[j].push_back(tmp);
		}
	}
	
	tm1.num = 1,tm1.vis[1] = true,tm1.cnt = 1,tm1.sum = 0;
	q.push(tm1);
	
	while(!q.empty())
	{
		tm1 = q.front();
		q.pop();
		
		if(tm1.cnt >= n)
		{
			ans = min(ans,tm1.sum);
			continue;
		}
		
		for(long long i = 0; i < head[tm1.num].size(); i++)
		{
			tm2 = tm1;
			tm2.num = head[tm1.num][i].v;
			
			if(tm1.vis[tm2.num] == true) continue;
			
			tm2.vis[tm2.num] = true;
			tm2.sum = tm1.sum + head[tm1.num][i].w;
			if(tm2.num <= kkk) tm2.cnt = tm1.cnt + 1;
			if(tm2.num > kkk) tm2.sum += city[tm2.num - kkk];
			
			q.push(tm2);
			
//			printf("num=%lld sum=%lld cnt=%lld\n",tm2.num,tm2.sum,tm2.cnt);
		}
	}
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
