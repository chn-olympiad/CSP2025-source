#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
struct zu
{
	string f,t;
}a[200005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string p,q;
		cin>>p>>q;
		a[i].f=p;
		a[i].t=q;
	}
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		int ans=0;
		if(x.size()!=y.size())
		{
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int p=x.find(a[i].f);
			if(p==-1)continue;
			string t=x;
			for(int j=p;j<p+a[i].f.size();j++)
			{
				t[j]=a[i].t[j-p];
			}
			if(t==y)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
