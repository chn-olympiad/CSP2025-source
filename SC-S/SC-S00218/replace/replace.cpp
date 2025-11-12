#include<bits/stdc++.h>
using namespace std;
int n,q,ans,k;
string a,b,o;
map<string,pair<string,int>>mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		mp[a]={b,mp[a].second+1};
	}
	while(q--)
	{
		ans=0;
		cin>>a>>b;
		if(a.size()!=b.size())cout<<0<<'\n';
		else
		{
			for(int i=0;i<int(a.size());i++)
			{
				k=i;
				while(a[k]!=b[k])k++;
				if(k!=i)
				{
					o=a.substr(i,k);
					if(b.substr(i,k)==mp[o].first)ans+=mp[o].second;
				}
				i=k;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}