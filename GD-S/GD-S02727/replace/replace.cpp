#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string u[100005];
string v[100005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>u[i]>>v[i];
	while(q--)
	{
		string s,t;
		cin>>s>>t;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int id=s.find(u[i]);
			if(id!=-1)
			{
				string xt="";
				for(int j=0;j<s.size();j++)
				{
					if(j!=id)xt+=s[j];
					else xt+=v[i],j+=u[i].size()-1;
				}
				if(xt==t)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
