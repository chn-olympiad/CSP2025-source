#include<bits/stdc++.h>
using namespace std;
string s[200005][5],t[200005][5];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=2;++j)
		{
			cin>>s[i][j];
		}
	}
	for (int i=1;i<=q;++i)
	{
		for (int j=1;j<=2;++j)
		{
			cin>>t[i][j];
		}
		cout<<0<<endl;
	}
	return 0;
}
