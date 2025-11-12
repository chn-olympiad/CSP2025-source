#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int pre[N], a[N];
int n, k;
struct prt{
	int l, r;
}w[N];
int len = 0;
typedef pair<int, int> PII;
bool cmp(prt x, prt y)
{
	if(x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
long long ans = 0;
long long f[N], num[N], in[N];
vector<int> e[N];
long long maxdep = 0;
void deptest(int u, long long dep)
{
	if(e[u].size() == 0) 
	{
		maxdep = max(maxdep, dep);
		return ;
	}
	for(int v : e[u])
	{
		deptest(v, dep+1);
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pre[i] = pre[i-1] ^ a[i];
	}
	//for(int i = 1; i <= n; i++) cout << pre[i] << " ";
	//cout << endl;

	for(int l = 1; l <= n; l++)
	{
		for(int r = l; r <= n; r++)
		{
			if((pre[r] ^ pre[l-1]) == k)
			{
				w[++len].l = l;
				w[len].r = r;
			}
		}
	}
	for(int i = 1; i <= len; i++)
	{
		for(int j = 1; j <= len; j++)
		{
			if(w[i].r < w[j].l)
			{
				e[i].push_back(j);
				in[j]++;
			}
		}
	}
	queue<PII> q;
	for(int i = 1; i <= len; i++)
	{
		if(in[i] == 0)
		{
			maxdep = 0;
			deptest(i, (long long)1);
			ans = max(ans, maxdep);
		}
	}
//	sort(w+1, w+1+len, cmp);
//	int st = -1, ls = -1;
//	for(int i = 1; i <= len; i++)
//	{
//		if(w[i].l > ls)
//		{
//			st = w[i].l;
//			ls = w[i].r;
//			ans++;
//			//cout << w[i].l << " " << w[i].r << endl;
//		}
//		
//	}
	cout << ans;
	return 0;
}
//O(1) query part xor of array
//
