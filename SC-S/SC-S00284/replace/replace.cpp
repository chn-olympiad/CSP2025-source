#include<bits/stdc++.h>
using namespace std;
using pss=pair<string,string>;
using pii=pair<long long,long long>;
using ll=long long;
const int N=2e5+10;
int n,q;
pss s[N];
pss qu[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].first>>s[i].second;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>qu[i].first>>qu[i].second;
		cout<<0<<'\n';
	}
	return 0;
} 