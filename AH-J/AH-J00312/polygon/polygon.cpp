#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,c;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a>>b>>c;
	if((a+b+c)>(2*max(a,max(b,c))))cout<<1%101;
	else cout<<0%101;
	return 0;
}
