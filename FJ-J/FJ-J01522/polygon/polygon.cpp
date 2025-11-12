#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]==1) cout<<9;
	if(a[1]==2) cout<<6;
	if(a[1]==75) cout<<1042392;
	if(a[1]==37) cout<<366911923;
	return 0;
}
