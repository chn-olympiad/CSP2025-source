#include <iostream>

using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,c = 0;
	cin>>n>>k;
	const int N = n;
	int a[N];
	for(int i = 0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			++c;
		}
	}
	
	cout<<c;
	
	return 0;
}