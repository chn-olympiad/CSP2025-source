#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fac(ll n){
	if(n==0)return 1;
	return (n * fac(n - 1)) % 998244353;
}
long long combine(ll n)
{
	ll sum = 0;
	for(int i = 0; i <= n; ++i)
	{
		int j = n - i;
		sum += (fac(i+j) / fac(i) / fac(j));
	}
	return sum;
}

ll cannot = 0;
void dfs(vector<int> len, ll maxl, ll curl, ll l, ll r, ll depth){
	if(l > r) 
	{
		return;
	}
	if(depth < 3 || curl <= maxl) ++cannot;
	
	for(int i = l; i < len.size(); ++i){
		dfs(len, maxl, curl + len[i], i + 1, r, depth+1);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n; vector<int> len;
	cin>>n;
	for(int i = n; i > 0 ; --i)
	{
		int tmp;
		cin>>tmp;
		len.push_back(tmp);
	}
	sort(len.begin(), len.end());
	
	if(n == 3)
	{
		if(len[2] < len[0] + len[1]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	
	for(ll i = len.size() - 1; i >= 2;--i)
	{
		ll maxl = len[i];
		dfs(len, maxl, 0, 0, i + 1, 1);
	}
	cout<<(combine(n) - cannot)%998244353-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
