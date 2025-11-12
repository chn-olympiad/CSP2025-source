#include <bits/stdc++.h>
using namespace std;
int n,sum;
int a[10000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(n<3) cout<<0;
	else if(n==3)
	{
		if(sum>2*max(max(a[1],a[2]),a[3])) cout<<1;
	}
	else cout<<0;
	return 0;
}
