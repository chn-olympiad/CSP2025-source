#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<t;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c;
		d=b*b-4*a*c;
		if(d<0)
		{
			cout<<"NO"<<endl;
		}
		else if(n==0)
		{
			a*=2;
			int gcd=__gcd(a,b);
			a/=gcd;
			b/=gcd*-1;
			if(a<0&&b<0)
			a*=-1,b*=-1;
			cout<<b;
			if(a!=1)cout<<'/'<<a;
			cout<<endl;
		}
		else ;
	}
	return 0;
}
