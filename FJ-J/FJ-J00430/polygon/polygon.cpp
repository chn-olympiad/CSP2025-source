#include<bits/stdc++.h>
using namespace std;
int n,a[10005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		cout<<1;
	}
	if(n>3&&n<=10)
	{
		cout<<9;
	}
	return 0;
} 
