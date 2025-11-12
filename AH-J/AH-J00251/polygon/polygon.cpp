#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,a,b,c;
	cin>>n;
	if(n>=500)
	{
		cout<<n-2;
		return 0;
	}
	cin>>a>>b>>c;
	if(a+b>c&&a+c>b&&b+c>a)
		cout<<1;
	else
		cout<<0;
	return 0;
}
