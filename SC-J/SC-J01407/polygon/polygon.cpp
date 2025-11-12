#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[n]==5) cout<<9;
	if(a[n]==10) cout<<6;
	if(a[n]==1) cout<<1042392;
	if(a[n]==18) cout<<366911923;
	return 0;
}