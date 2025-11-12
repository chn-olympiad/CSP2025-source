#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin >>n >>m;
	string s;
	cin >>s;
	long long a[n+1];
	for (long long i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	long long t=1;
	for (long long i=n;i>0;i--)
	{
		t*=i;
	}
	cout <<t;
	return 0;
}
