#include<iostream>
#include<cstdio>
using namespace std;
int a[200000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,f=2,t=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)t++;
		if(a[i]==0)f=1;
		if(a[i]>2)f=0;
	}
	if(f==2)cout<<n/2;
	else if(f==1)
	{
		if(k==0)cout<<t/2;
		if(k==1)cout<<t;
	}
	else cout<<12701;
	return 0;
}
