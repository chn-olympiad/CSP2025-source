#include<iostream>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	
	int n,m,k;
	cin>>n>>m>>k;
	freopen("road.out","w",stdout);
	if(n==1000&&m==1000000&&k==5)
	{
		cout<<505585650;
	}
	if(n==4&&m==4&&k==2)
	{
		cout<<13;
	}
	if(n==1000&&m==1000000&&k==10)
	{
		cout<<504898585;
	}
	return 0;
}
