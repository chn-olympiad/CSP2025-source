#include<bits/stdc++.h>
using namespace std;
long long s,n,m,i,j,k,z[5010],l,d,a,b,c;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	m=max(a,max(b,c));
	if(m*2<a+b+c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
