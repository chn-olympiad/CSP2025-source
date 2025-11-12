#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s=0;
	cin>>n;
	if(n<=3)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n-2;i++)
	{
		cin>>a[i];
		s+=i*(n-i-1);
	}
	cout<<s;
	return 0;
}