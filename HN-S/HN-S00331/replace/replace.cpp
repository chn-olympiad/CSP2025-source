#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,string>mp;
ll n,q,cnt;
string x[200001],y[200001];
void dfs(string xx,string yy)
{
	if(xx==yy)
	{
		cnt++;
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(xx.find(x[i]))
		{
			ll sss=0;
			for(ll j=0;j<xx.size();j++)
			{
				ll flag=0;
				for(ll k=0;k<x[i].size();k++)
				{
					if(xx[j+k]!=x[i][k])
					{
						flag=1;
						break;
					}
				}
				if(!flag)
				{
					for(ll k=j;k<j+ll(x[i].size());k++)
					{
						xx[k]=x[i][k-j];
					}
					break;
				}
			}
			dfs(xx,yy);
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		mp[x[i]]=y[i];
		mp[y[i]]=x[i];
	}
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		dfs(x,y);
		cout<<cnt<<endl;
	}
	return 0;
}
