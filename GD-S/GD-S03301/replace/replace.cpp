#include <iostream>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int a[n],b[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]<=a[i-1])
		{
			cout<<a[i];
		}
	}
    return 0;
}
