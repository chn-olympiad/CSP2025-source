#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
long long  a[N],sum[N];
bool check(int mid)
{
	int res=0;
	int j=1;
	for(int i=1;i<=n;i++)
	{
		if((sum[i] xor sum[j])==k)
		{
			res++;
			j=i;
		}
	} 
	if(res>=mid)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sum[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1] xor a[i];
	}
	int l=0,r=5e5;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
}
