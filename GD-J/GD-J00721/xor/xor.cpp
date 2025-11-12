#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N = 5e5 + 10;
int n,k,nowr,ans,a[N],sum[N];
unordered_map <int,vector <int>> che;
vector <pair <int,int>> gtlr;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	che[0].push_back(0);
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
		if(che.count(k ^ sum[i]))
			gtlr.push_back(make_pair(i,che[k ^ sum[i]].back()));
		che[sum[i]].push_back(i);
	}
	if(gtlr.empty())
	{
		cout << 0;
		return 0;
	}
	sort(gtlr.begin(),gtlr.end());
	nowr = gtlr[0].first;
	ans = 1;
	n = gtlr.size();
	for(int i = 1;i < n;i++)
	{
		if(gtlr[i].second >= nowr)
		{
			nowr = gtlr[i].first;
			ans++;
		}
	}
	cout << ans;
	return 0;
}

