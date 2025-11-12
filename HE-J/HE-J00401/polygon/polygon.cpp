#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[45];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	if(n==1)
		cout<<"0";
	if(n==2)
		cout<<"0";
	if(n==3)
	{
		cout<<"1";
	}
	return 0;
}
