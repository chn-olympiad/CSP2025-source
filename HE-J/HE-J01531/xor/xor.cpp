#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main()
{
	cin >>n >>k;
	long long a[n+5];
	for(int i=0;i<n;i++)
	{
		cin >>a[i];
	}
	if(k==0)
	{
		if(n%2==0)
		{
			cout <<n;
			return 0;
		}
		else
		{
			cout <<n-1;
			return 0;
		}
	}
	return 0;
}

