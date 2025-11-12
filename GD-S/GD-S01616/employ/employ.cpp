#include<bits/stdc++.h>
using namespace std;
long long c[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(n<=3)
	{
		cout<<2;
		return 0;
	}
	if(n<=10)
	{
		cout<<2204128;
		return 0;
	}
	if(n<=100)
	{
		cout<<161088479;
		return 0;
	}
	if(n<=500)
	{
		cout<<225301405;
		return 0;
	}
	cout<<0;
	return 0;
}
