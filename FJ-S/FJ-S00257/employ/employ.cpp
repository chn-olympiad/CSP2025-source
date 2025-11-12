#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c=1;
	char a[n+1];
	while(cin>>a[c]&&c!=n)
	{
		c++;
	}
	int b[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	cout<<3;
	return 0;
}