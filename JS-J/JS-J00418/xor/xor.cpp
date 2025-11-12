#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10,M = 1100000;
int a[N],n,k,ans;
vector<int> b[M];
vector<pair<int,int> > e;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i],a[i] ^= a[i - 1],b[a[i]].push_back(i);
	for(int i = 1 ; i <= n ; i ++)
	{
		int c = a[i - 1] ^ k;
		if(b[c].size() && b[c][b[c].size() - 1] >= i - 1)
		{
			int d = upper_bound(b[c].begin(),b[c].end(),i - 1) - b[c].begin();
			e.push_back({i,b[c][d]});
		}
	}
	if(!e.size())
	{
		cout << 0;
		return 0;
	}
	sort(e.begin(),e.end());
	e.push_back({n + 1,n + 1});
	int l = e[0].first,r = e[0].second;
	for(auto x : e)
	{
		int ll = x.first,rr = x.second;
		if(ll <= r && rr < r)
			r = rr;
		else if(ll > r)
			l = ll,r = rr,ans ++;
	}
	cout << ans;
	return 0;
}