#include<iostream>
#include<cstdio>
using namespace std;
long long n,k,a[5005],sum;
int main()
{
	freopen("xor.in",r,stdin);
	freopen("xor.out",w,stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)sum++;
	}
	cout<<sum;

	return 0;	
} 
