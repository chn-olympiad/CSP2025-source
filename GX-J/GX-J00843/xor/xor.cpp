#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w".stdout);
	int n,a,m,max=0;
	for(int i=1;i<=n;i++)
	{
		cin>>n>>m;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a>=n&&a<=m)
		{
			if(a>=max) max=a;
		}
	}
	cout<<a;
	return 0;
}
