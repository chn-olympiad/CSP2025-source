#include<bits/stdc++.h>
#define def(i,a,b) for(int i=a;i<=b;i++)
#define udef(i,a,b) for(int i=a;i>=b;i--)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define m(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
using namespace std;
typedef pair<long long ,long long> pii;
typedef int i32;
typedef long long i63;
const int N = 1e6 + 5, INF = 0x3f3f3f3f;
i32 n,m,k; 
vector<pii> a[N];
i32 c[12][N];
priority_queue<pii,vector<pii>,greater<pii> > q; 
bool f[N];
void work()
{
	i32 g = 0;
	i63 ans = 0;
	for(auto now : a[1])
		q.push({now.se,now.fi});
	f[1] = 1;
	def(i,1,n+k)
	{
		while(!q.empty() && f[q.top().se]) q.pop();
		pii t = q.top();
		if(t.se <= n) g ++;
		if(g == n) break;
		f[t.se] = 1;
		ans += t.fi;
		for(auto now : a[t.se]) q.push({now.se,now.fi}); 
	}
	cout << ans << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	i32 u,v,w;
	cin >> n >> m >> k;
	def(i,1,m)
	{
		cin >> u >> v >> w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});	
		
	}
	def(i,1,k)
	{
		cin >> c[i][0];
		def(j,1,n)
		{
			cin >> c[i][j];
			a[i+n].push_back({j,c[i][j]});
			a[j].push_back({i+n,c[i][j]}); 
		}
	}
	work();
	return 0;
}

