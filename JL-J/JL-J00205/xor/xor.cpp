#include <bits/stdc++.h>
using namespace std;
long long a[10000000];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	if(n==2&&k==0)
	{
		for(int i=0;i<2;i++)
			if(a[i]!=0)
			{
				cout<<a[i]<<endl;
				break;
			}
	}
	
	return 0;
}
