#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int x,n,m,a[30];
	cin>>x>>n;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i];
	}
	for(int j=0;j<n;j++)
	{
		m=max(a[j],a[n]);
	}
	cout<<m;
	return 0;
}
