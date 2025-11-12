#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int M = 1e7+10;
int fa[N],n,m,k,c[1111],cnt,ans,sum=0;
struct node{
	int u, v, dis;
}edge[M];
bool cmp(node ed1, node ed2)
{
	return ed1.dis<ed2.dis;
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int f1, f2;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].dis;
		f1 = edge[i].u , f2 = edge[i].v ;
//		cout << f1 << ' ' << f2 << '\n';
		sum++;
		
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			sum++;
			edge[sum].u = i+m;
			edge[sum].v = j;
			cin >> edge[sum].dis;
//			sum++;
		}
	}
	for(int i = 1; i <= sum; i++)fa[i] = i;
//	cout << sum << '\n';
//	cout << sum << '\n';
	sort(edge+1,edge+sum+1,cmp);
//	f1 = 1, f2 = 2;
//	ans = edge[f1].dis + edge[f2].dis;
	for(int i = 1; i <= sum; i++)
	{
		f1 = edge[i].u , f2 = edge[i].v ;
//		cout << "te: " << f1 << ' ' << f2 << '\n';
		if(find(f1)!=find(f2))
		{
			
			ans += edge[i].dis;
			cnt++;
			fa[f1] = f2; 
//			cout << "an "<< ans << '\n';
		}
		if(cnt == n+k-1)break;
	}
	cout << ans << '\n';
	return 0;
} 
