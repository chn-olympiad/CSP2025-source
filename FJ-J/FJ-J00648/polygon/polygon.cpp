#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in"."r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	int a[5005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(n<3) {cout<<0;return 0;}
	if(n==3 && sum>a[n]*2) {cout<<1;return 0;}
	if(n==3 && sum<=a[n]*2) {cout<<0;return 0;}
	else cout<<9;
	return 0;
}
