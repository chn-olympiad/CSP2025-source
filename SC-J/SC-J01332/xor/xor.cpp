#include<iostream>
#include<cstdio>
using namespace std;
int a[500005];
int main()
{
	int n,k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=0;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		x+=a[i];
		if(x==k||x==k*k||x==k*k*k||x==k*k*k*k||a[i]==k||a[i]==k*k||a[i]==k*k*k||a[i]==k*k*k*k||a[i]*a[i]==k||a[i]*a[i]*a[i]==k
		||a[i]*a[i]*a[i]*a[i]==k||a[i]*a[i]==k*k*k) 
		{
			num++;
			x=0;
		}
	}
	cout<<num;
	return 0;
}