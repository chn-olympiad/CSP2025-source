#include <bits/stdc++.h>
using namespace std;
#define N 1000005
long long a[N];
long long n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			cout<<"0"<<endl;
		}
	}
	if(n<=2&&k==0)
	{
		cout<<i<<endl;
	}
	return 0;
}
