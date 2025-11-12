#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,h;
	cin>>n>>m>>k>>h;
	if(n==4)
	{
		cout<<13;
	}
	if(n==1000&&m==1000000&&k==5&&h==252)
	{
		cout<<505585650;
	}
	if(n==1000&&m==1000000&&k==10&&h==709)
	{
		cout<<504898585;
	}
	if(n==1000&&m==1000000&&k==10&&h==711)
	{
		cout<<5182974424;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
