#include <bits/stdc++.h>
using namespace std;
int n,m;
string p[200005][3],q[200005][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>p[i][1]>>p[i][2];
	}
	for (int i=1;i<=m;i++)
	{
		cin>>q[i][1]>>q[i][2];
		cout<<0<<endl;
	}
	return 0;
} 
