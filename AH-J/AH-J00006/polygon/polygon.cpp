#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
long long sum;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	else
		cin>>a>>b>>c;
	if(a+b+c>2*max(a,max(b,c)))
		cout<<1;
	else
		cout<<0;
	return 0;
}
