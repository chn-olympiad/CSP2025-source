#include <iostream>
#include <algorithm>
using namespace std;
int a[5005];
int suma[5005];
long long c[5005][5005];
long long ans=0;
int MOD=998244353;
int main()
{
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	int maxn=max(a,max(b,c));
	if (2*maxn<a+b+c)
	{
		cout<<1;
	}
	cout<<0;
	return 0;
}
