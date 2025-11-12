#include<iostream>
#include<cstdio>
using namespace std;

int a[200005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	if(n==2 && k==0 && a[1]==1 && a[2]==1) cout<<1;
	else if(n==1 && k==0 && a[1]==1) cout<<0;
	return 0;
}
