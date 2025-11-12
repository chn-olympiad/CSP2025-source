#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int n,a[2000005];
const int MOD=998244353;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<n-2;
	return 0;
}
