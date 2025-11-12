#include <iostream>

using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int m,n,c = 1;
	cin>>n>>m;
	const int xx = m*n;
	int a[xx];
	for(int i = 0;i<xx;++i)
	{
		cin>>a[i];
	}
	
	for(int i = 1;i<xx;++i)
	{
		int t = a[0];
		if(a[i]>t)
		{
			++c;
		}
	}

	if(c<=n)
	{
		cout<<'1'<<' '<<c;
		return 0;
	}

	int k = c/(n)+1;
	
	if(k%2==0)
	{
		cout<<k<<' '<<n-(c%n)+1;
	} else
	{
		cout<<k<<' '<<c%n;
	}
	
	return 0;
}