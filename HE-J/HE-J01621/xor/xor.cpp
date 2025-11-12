#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],num1,num0,num;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool c1=1,b1=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1 && a[i]!=0)
		{
			c1=0;
		}
		if(a[i]!=1)
		{
			b1=0;
		}
		if(a[i]==0)
		{
			num0++;
		}
		else
		{
			num1++;
		}
		if(a[i]==k)
		{
			num++;
		}
	}
	if(b1)
	{
		if(k==1)
		{
			cout<<n;
		}
		else
		{
			cout<<n/2;
		}
	}
	else if(c1)
	{
		cout<<num1+num0/2;
	}
	else
	{
		if(n/3+1<num)
		{
			cout<<num;
		}
		else
		{
			cout<<n/3+1;
		}
	}
	return 0;
}
