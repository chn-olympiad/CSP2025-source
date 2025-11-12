#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 5;
ll n,k,a[N],sum[N],cnt;
vector<pair<ll,ll> > line;

bool cmp(pair<ll,ll> x,pair<ll,ll> y)
{
	return x.second < y.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(int l = 1;l <= n;l++)
	{
		for(int r = l;r <= n;r++)
		{
			if((sum[r] ^ sum[l - 1]) == k)
			{
				line.push_back({l,r});
				break;
			}
		}
	}
	
	sort(line.begin(),line.end(),cmp);
	
	int len = line.size(),l = 0,r = 0,ans = 0;
	for(int i = 0;i < len;i++)
	{
		ll nl = line[i].first,nr = line[i].second;
		if(nl > r)
		{
			l = nl,r = nr;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
