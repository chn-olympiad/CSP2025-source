#include<bits/stdc++.h>
using namespace std;
struct ___
{
	string a,b;
} s[200005];
int main()
{
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++) cin>>s[i].a>>s[i].b;

	while(q--)
	{
		string u,v;
		cin>>u>>v;
		if(u.size()!=v.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(int i=1; i<=n; i++)
		{
			if(s[i].a.size()>u.size()) continue;
			for(int j=0; j+s[i].a.size()-1<u.size(); j++)
			{
				bool op=true;
				//cout<<i<<' '<<"size: "<<s[i].a.size()<<'\n';

				for(int k=0; k<s[i].a.size()&&op; k++)
				{

					//	cout<<u[j+k]<<' '<<s[i].a[k]<<'\n';

					if(u[j+k]!=s[i].a[k])
					{
						op=false;
					}

				}
				if(!op) continue;

				for(int k=0; k<s[i].b.size()&&op; k++)
				{
					//	cout<<v[j+k]<<' '<<s[i].b[k]<<'\n';

					if(v[j+k]!=s[i].b[k])
					{
						op=false;
					}
				}
				for(int k=j+s[i].a.size(); k<n; k++)
				{
					if(u[j]!=v[j]);
					op=false;
				}
				if(op)
				{
					//	cout<<"can: "<<i<<' '<<j<<'\n';
					ans++;
				}
				if(u[j]!=v[j]) break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
