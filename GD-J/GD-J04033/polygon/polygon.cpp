#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c,n,d;
	cin>>n>>a>>b>>c;
	d=max(a,b); 
	d=max(d,c);
	if(d*2<a+b+c)
	{
		cout<<1;
	}
	return 0;
}
