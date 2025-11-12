#include<bits/stdc++.h>
using namespace std;
int gun[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int max11=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>gun[i];
		max11=max(max11,gun[i]);
	}
	if(n==3)
	{
		int sum=gun[1]+gun[2]+gun[3];
		if(sum>max11*2)
		cout<<1;
		else
		cout<<0;
	}
	return 0;
}
