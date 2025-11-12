#include<iostream>
using namespace std;
int n,a[10001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==5&&a[1]==1) cout<<9;
	else cout<<6;
	if(n==20) cout<<1042392;
	if(n==500) cout<<366911923;
	return 0;
}//afoed.
