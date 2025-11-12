#include<algorithm> 
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int a[1000000];
int hcb(int q,int min)
{
	int s=0;
	if(min<=0)
	{
		s=1;
	}
	if(q<=0)
	{
		return s;
	}
	for(int i=q-1;i>=1;i--)
	{
		s+=hcb(i,min)%998244353;
	}
	for(int i=q-1;i>=1;i--)
	{
		s+=hcb(i,min-a[q])%998244353;
	}
	return s%998244353;
}
int main()
{
	freopen("polygon.in","s",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=3;i<=n;i++)
	{
		sum+=hcb(i,a[i]*2);
	}
	cout<<sum;
}