#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5+60;
int a[N];
struct q{
	int l,r;
	int len ;
};

vector<q>op;
bool cmp(q a,q b)
{
	return a.len < b.len;
}
bool v[N];
ll n, k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	bool f = true;
	for(int i = 1; i <= n ; i++)
	{
		cin >> a[i];
		if(a[i] > 1) f = false;
	}
	if(f&&n > 1e3)
	{
		int cnt = 0;
		for(int i = 1; i <= n ; i++)
		{
			if(a[i] == k)
			{
				cnt++;
			}
			else
			{
				if(!v[i-1]&&a[i-1] != k)
				{
					cnt++;
					v[i-1] = true;
					v[i] = true;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
			
	for(int l = 1; l <= n ; l++)
	{
		int u = a[l];
		if(u == k)
		{
			op.push_back({l,l,1});
			continue;
		}
		for(int r = l+1; r <= n; r++)
		{
			u = u^a[r];
			if(u == k)
			{
				op.push_back({l,r,r-l+1});
				break;
			}
		}
	}
	sort(op.begin(),op.end(),cmp);
	ll cnt = 0;
	for(auto h : op)
	{
		bool ok = true;
		for(int j = h.l;j <= h.r; j++)
		{
			if(v[j]) 
			{
				ok = false;
				break;
			}
		}
		if(ok)
		{
			cnt++;
			for(int j = h.l;j <= h.r; j++)
			{
				v[j] = true;
			}
		}
	}
	cout<<cnt;
	return 0;
}