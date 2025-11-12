#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n>>m;
	int s=0,r0;
	cin >>r0;
	for (int i=1;i<n*m;i++)
	{
		int s0;
		cin >> s0;
		if(s0>r0)s++;
	}
	int c,r;
	c = s/n;
	r = s%n;
	c++;
	if (c%2==0)
	{
		r = n-r;
	}
	else
	{
		r++;
	}
	cout << c <<" "<< r;
	return 0;
}
