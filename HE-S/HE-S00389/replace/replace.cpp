#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a,b;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a;
		cin>>b;
		cout<<a.size()-b.size()<<endl;
	}
	return 0;
}
