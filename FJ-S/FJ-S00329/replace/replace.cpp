#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,int> M;
int n,m;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string x,y;
		cin>>x>>y;
		M[make_pair(x,y)]++;
	}
	for(int i=1;i<=m;i++)
	{
		string x,y;
		cin>>x>>y;
		cout<<M[make_pair(x,y)]<<'\n';
	}
	return 0;
}