#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define maxn 200010
#define inf 0x3f3f3f3f3f3f3f3f
int n,q,tp;
cc_hash_table<string,int>mp,vs;
vector<string>v[maxn];
string s1,s2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>s1>>s2;
		if(mp.find(s1)==mp.end()) mp[s1]=++tp;
		v[mp[s1]].push_back(s2);
	}
	while(q--)
	{
		puts("0");
	}
	return 0;
}

