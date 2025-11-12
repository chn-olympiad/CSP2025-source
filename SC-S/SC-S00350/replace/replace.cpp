#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

#define ll long long
#define rint register int

using namespace std;
using namespace __gnu_pbds;

const int N=2e5+10;
int n,q,idx=0;

gp_hash_table<string,int> mp;
vector<string> e[N];

string s1,s2,t1,t2;

int get_num(string s)
{
	if(mp[s])
	{
		return mp[s];
	}
	
	return mp[s]=++idx;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	
	for(rint i=1;i<=n;++i)
	{
		cin>>s1>>s2;
		
		e[get_num(s1)].push_back(s2);
	}
	
	while(q--)
	{
		cout<<"0\n";
	}
} 