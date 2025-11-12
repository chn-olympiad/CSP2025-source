#include<bits/stdc++.h>
using namespace std;
long long ans=1,e,n,m;
string s,t;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>s>>t;
	}
	for (int i=1;i<=m;i++)
	{
		cin>>s>>t;
		if (s.size()!=t.size())
		cout<<"0\n";
		else cout<<pow(2,n)<<"\n";
	}
	return 0;
 } 
