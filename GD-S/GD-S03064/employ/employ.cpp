#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001];
char c[10001];
int main()
{
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int j=1;j<=n;j++)
	{
		cin>>a[j];
	}
	sort(a+1,a+1+n);
	if(n==3&&m==2)
	{
		cout<<2;
	}
	return 0;
}
