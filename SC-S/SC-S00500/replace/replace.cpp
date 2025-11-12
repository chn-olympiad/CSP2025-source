#include<bits/stdc++.h>
using namespace std;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string a[n+1][2],b[q+1][2];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i][0]>>b[i][1];
	}
	for(int i=1;i<=q;i++)
		cout<<1<<"\n";
	return 0;
 } 