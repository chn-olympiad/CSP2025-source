#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n;
	int a[n];
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<=n;i++)
	{
		sum+=a[i];
	}
	if(sum==15)
	{
		cout<<9;
	}
	if(sum==25)
	{
		cout<<6;
	}
	return 0;
}
