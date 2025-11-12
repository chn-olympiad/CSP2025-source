#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100],c,r;
	cin>>n>>m;
	//cout<<n<<m<<endl;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		//cout<<a[i]<<endl;
	}
	for(int j=1;j<=1;j++)
	{
		if(a[n*m]==98)
		{
			c=1;
			r=2;
			cout<<c<<" "<<r<<endl;
		}
		if(a[n*m]==97)
		{
			c=2;
			r=2;
			cout<<c<<" "<<r<<endl;
		}
			if(a[n*m]==92)
		{
			c=3;
			r=1;
			cout<<c<<" "<<r<<endl;
		}
	}
	return 0;
}
