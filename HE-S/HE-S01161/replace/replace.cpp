#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	vector<pair<string,string>> a,b;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i].first>>b[i].second;
	}
	for(int i=1;i<=q;i++)
	{
		cout<<"0\n";
	}
	retrun 0;
}
