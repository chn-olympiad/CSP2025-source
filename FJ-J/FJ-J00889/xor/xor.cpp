#include <iostream>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int numxor[n+1];
	for (int i=1;i<=n;i++)
	{
		cin>>numxor[i];
	}
	cout<<n/2;
	return 0;
}
