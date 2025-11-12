#include<bits/stdc++.h>
using namespace std;
string s[200100][2],t[200100][2],k[200100],l[200100],f[200100];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<"\n";
	}
	return 0;
}
