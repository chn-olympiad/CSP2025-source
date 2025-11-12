#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define Endl '\n'
using namespace std;
int n,ans,a[5005];
const long long MOD=998244353;
bool check(vector<int> v)
{
	int sum=0,maxx=-1;
	for(int i=0;i<v.size();i++)
	{
		sum+=v[i];
		maxx=max(maxx,v[i]);
	}
	return sum>maxx*2;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=(1<<n);i++)
	{
		if(__builtin_popcount(i)<3)
			continue;
		vector<int> t;
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				t.push_back(a[j+1]);
		if(check(t))
			ans=(ans+1)%MOD;
	}
	cout<<ans;
	return 0;
}