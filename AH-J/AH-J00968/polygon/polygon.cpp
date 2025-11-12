#include<bits/stdc++.h>
using namespace std;
int n;
int a[50005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3])))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
}
