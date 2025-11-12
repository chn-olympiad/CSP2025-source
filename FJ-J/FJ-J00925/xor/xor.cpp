#include<bits/stdc++.h>
using namespace std;
using lld = long long;
const lld siz = 5e5+5;
const lld mod = 1e9+7;
using pll = pair<lld,lld>;


lld pre[siz];
lld n,k,a[siz];
vector<pll> vec;
map<lld,lld> lst;
bool cmp(pll x,pll y)
{
	return x.second < y.second;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	lld sum = 0;
	lst[0] = n+1;
	for(int i=n;i>=1;i--)
	{
		sum^=a[i];
		lld ned = sum^k;
		if(lst[ned]!=0)
			vec.push_back({i,lst[ned]-1});
		lst[sum] = i;
	}
	sort(vec.begin(),vec.end(),cmp);
	lld ed = vec[0].second,l = vec.size(),ans = 1;
	for(int i=1;i<l;i++)
	{
		if(vec[i].first>ed)
		{
			ans++; ed = vec[i].second; 
		}
	}
	printf("%lld",ans);
	return 0;
}

