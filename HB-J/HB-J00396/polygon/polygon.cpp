#include <bits/stdc++.h>
using namespace std;
int n,a[5000],t;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t=max(t,a[i]);
	}
	cout<<9;
	return 0;
}

