#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<vector<string> >s(n+5,vector<string>(2,""));
	vector<vector<int> >a(n+5,vector<int>(2,0));
	for(int i=1;i<=n;++i)
	{
		cin>>s[i][0]>>s[i][1];
		int a0=s[i][0].find("b"),a1=s[i][1].find("a");
		cout<<a0<<' '<<a1<<'\n';
	}
	return ;
}

signed main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	int t;t=1;
	while(t--)solve();
	return 0;
}
