#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005],t[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i]>>t[i];
	for(int i=1;i<=q;i++)
	{
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			int x=a.find(s[j]),y=b.find(t[j]);
			if(x!=-1&&y!=-1&&x==y&&a.substr(0,x)==b.substr(0,x)&&a.substr(x+s[j].size())==b.substr(x+s[j].size())) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
