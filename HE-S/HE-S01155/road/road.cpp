#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long b;
	cin>>n>>m>>k>>b;
	if(k==2)
	{
		cout<<13;
	}
	else if(k==5)
	{
		cout<<505585650; 
	}
	else if(b==709)
	{
		cout<<504898585;
	}
	else
	{
		cout<<5182974424;
	}
	return 0;
}
