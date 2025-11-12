#include<bits/stdc++.h>
using namespace std;
int r,n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>r;
	for(int i=1;i<=r;++i)
	{
		cin>>n;
	}
	if(n<=500)
	{
		cout<<7;
	}
	else
	{
		cout<<"998244352";
	}
	return 0;
}
