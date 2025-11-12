#include<bits/stdc++.h>
using namespace std;
long long c(int x)
{
	long long s=1;
	for(int i=1;i<x;i++)
	{
		s*=i;
	}
	return s;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	cout<<c(n)/(c(m)*c(n-m));
	return 0;
}
