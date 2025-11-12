#include<bits/stdc++.h>
using namespace std;
int n,m,s[1001][1001],a[1000001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int now=a[1];
	sort(a+1,a+1+(n*m),greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		int lie=(i-1)/n+1;
		int hang=i%n;
		if(hang==0) hang=n;
//		cout<<lie<<" "<<hang<<" "<<a[i]<<endl;
		if(lie%2==0) s[lie][m-hang+1]=a[i];
		else s[lie][hang]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]==now) cout<<i<<" "<<j<<endl,exit(0);
		}
	}
}
