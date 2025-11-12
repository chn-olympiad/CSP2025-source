#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin)
	freopen("polygon.out","w",stdout)
	int n;
	int a[99999]={0}
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<pow(3,n-3);
	return 0;
}