#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	bool f=0;
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if (k==0)
		{
			f=1;
		}
	}
	if (f)
	{
		cout<<1;
		return 0;
	}
	cout<<n/2;
	return 0;
}
