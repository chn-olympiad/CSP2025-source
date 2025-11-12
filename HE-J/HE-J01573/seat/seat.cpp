#include <iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;
	cin >>n >> m;
	int a[n*m],r,c,R;
	for (int i = 1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	R = a[1];
	int q = 100-R+1;
	c =q/n + 1;
	if (m>2)
	{
		r = q%m;
	}
	else
	{
		r = q%m+1;
	}
	cout << c <<" "<< r;
	return 0;
}
