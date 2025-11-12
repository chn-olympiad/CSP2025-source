#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k;
int head[4000005],cnt;
int d[4000005];

struct bian
{
	int x;
	int y;
	int w;
}g[4000005];
priority_queue <bian,vector<bian>,greater<bian> > q;
bool operator > (const bian & x,const bian & y)
{
	return x.w > y.w;
}

/*
void ad(int x,int y,int w)
{
	//maybe bug
	g[++cnt].to = y;
	g[++cnt].nxt = head[x];
	g[++cnt].w = w;
	head[x] = cnt;
}
*/

int find(int x)
{
	if(d[x] == x)
		return d[x];
	else
	{
		d[x] = find(d[x]);
		return d[x];
	}
}

void un(int x,int y)
{
	int xn = find(x);
	int yn = find(y);
	d[xn] = yn;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> k;
	int xxx,yyy,www;
	int cnt = 0;
	for(int i = 1;i <= m;i++)
	{
		cin >> xxx >> yyy >> www;
		q.push(bian{xxx,yyy,www});
	}
	
//	sort(g + 1,g + cnt + 1,cmp);
	if(k == 0)
	{
		//kus
	//	memset(d,0x3f3f3f,sizeof(d));
		for(int i = 1;i <= 2 * n;i++)
			d[i] = i;
		int ans = 0;
		while(!q.empty())
		{
			bian tmp = q.top();
			q.pop();
			if(find(tmp.x) != find(tmp.y))
			{
				un(tmp.x,tmp.y);
				ans += tmp.w;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
