#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freoprn("number.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(k==0)
	{
		cout<<1;
	}
	else if(k<=255)
	{
		cout<<2;
	}
	else if(k>255)
	{
		cout<<k-1;
	}
	else
	{
		cout<<k+1;
	}
	return 0;
}
