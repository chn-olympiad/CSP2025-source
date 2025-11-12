#include <bits/stdc++.h>
using namespace std;

long long ans3 = 1e9,n,m,k,c[1015],g[15][100005];
struct bi
{
	int a,b,w;
	int f;
}a[1300005],b[1000005];
vector <bi> v;
bool fl[1300005];
bool cmp(bi a,bi b)
{
	return a.w < b.w;
}
int f[1300005];
int find(int x)
{
	if(f[x] != x) return f[x] = find(f[x]);
	return f[x];
}
void dfs(int x,int cnt,long long sum)
{
	if(x > k)
	{
		for(int i = 1;i <= cnt;i++) b[i] = a[i];
		sort(b + 1,b + cnt + 1,cmp);
//		cout << sum << ' ' << cnt << '|';
		for(int i = 1;i <= cnt;i++) f[i] = i;
		for(int i = 1;i <= cnt;i++)
		{
			int fx = find(b[i].a),fy = find(b[i].b);
	//		cout << a[i].a << ' ' << a[i].b << ' ' << a[i].w << '|';
			if(fx == fy||fx > n||fy > n) continue;
			f[fx] = fy;
			sum += a[i].w;
		}
//		cout << endl;
		int p = 0;
		for(int i = 1;i <= n;i++) if(f[i] == i) p++;
		if(p == 1) ans3 = min(ans3,sum);
		return;
	}
	dfs(x + 1,cnt,sum);
	int p = cnt,l = cnt;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			l++;
			a[l] = {i,j,g[x][i] + g[x][j]};
		}
	}
	dfs(x + 1,l,sum + c[x + n]);
	for(int i = p;i <= l;i++) a[i] = {0,0,0};
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int cnt = 0;
	for(int i = 1;i <= m;i++)
	{
		int u,vv,w;
		cin >> u >> vv >> w;
		a[i] = {u,vv,w};
		v.push_back({u,vv,w,0});
	}
	if(k == 0)
	{
		sort(v.begin(),v.end(),cmp);
		for(int i = 1;i <= n;i++) f[i] = i;
		long long ans = 0;
		for(int i = 0;i < v.size();i++)
		{
			int fx = find(v[i].a),fy = find(v[i].b);
			if(fx == fy) continue;
			f[fx] = fy;
			ans += v[i].w;
		}
		cout << ans;
		return 0;
	}
	int t = n;
	for(int i = n + 1;i <= n + k;i++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j++)
		{
			cin >> g[i - n][j];
		}
		for(int j = 1;j <= n;j++)
		{
			for(int k = j + 1;k <= n;k++)
			{
				if(j != k) v.push_back({j,k,g[i - n][j] + g[i - n][k],i});
			}
		}
	}
	if(k <= 5)
	{
		dfs(1,n,0);
		cout << ans3;
		return 0;
	}
	sort(v.begin(),v.end(),cmp);
//	for(int i = 1;i <= n + k;i++) f[i] = i;
//	int sum = 0;
//	for(int i = 0;i < v.size();i++)
//	{
//		int fx = find(v[i].a),fy = find(v[i].b);
//		cout << i << ' ';
//		cout << fx << ' ' << fy << endl;
//		if(fx == fy) continue;
//		bi w = v[i];
////		cout << w.a << '|' << w.b << ' ' << w.w << endl;
//		if(v[i].f)
//		{
//			if(fl[v[i].f])
//			{
//				sum += v[i].w;
//				f[fx] = fy;
//			}
//			else
//			{
//				if(i < v.size() - 1)
//				{
//					if(v[i].w + c[v[i].f] > v[i + 1].w + ) swap(v[i],v[i + 1]),i--;
//					else
//					{
//						f[fx] = fy;
//						sum += v[i].w + c[v[i].f];
//					}
//				}
//				else
//				{
//					sum += v[i].w + c[v[i].w];
//					fl[i] = true;
//				}
//			}
//		}
//		else
//		{
//			f[fx] = fy;
//			sum += v[i].w;
//		}
//	}
//	cout << sum;
	return 0;
}
