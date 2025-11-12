#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
	cin >>n;
	long long a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
		if(a[i>m])      m=a[i];
	}
	if(m==1)
	{
		cout <<n;
		return 0;
	}
	return 0;
}

