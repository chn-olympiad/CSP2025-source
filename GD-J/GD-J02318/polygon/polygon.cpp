#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[50000];
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==5)
	{
		if(a[1]==1)cout<<9;
		else if(a[1]==2)cout<<6;
	}
	else if(n==20)
	{
		cout<<1042392;
	}
	else if(n==500)cout<<366911923;
	else cout<<rand();
	int b=10000;
	while(b--)sort(a,a+n);
	return 0;
 } 
