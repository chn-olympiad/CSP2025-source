#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],a1,b[15],c[15];
int main( )
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		a1=a[1];
	}
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(a[i]>a[j])
			{
				a[i]=a[1];
			}
		}
	}
	cout<<n<<" "<<m;
	return 0;
}
