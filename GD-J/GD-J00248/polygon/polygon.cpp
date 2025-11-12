#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a,b,c;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	if(a>=b+c || b>=c+a || c>=a+b)
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	return 0;
} 
