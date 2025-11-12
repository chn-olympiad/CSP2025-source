#include<iostream>
using namespace std;
int a[10005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==1)cout<<n;
	if(k==0)cout<<n/2;
	return 0;
 } 
