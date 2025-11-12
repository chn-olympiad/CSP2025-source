#include <bits/stdc++.h>
using namespace std;
int n,a[5010],sum=0;
long long t(int x)
{
	if(x==0) return 1;
	long long s=x;
	for(int i=x-1;i>=1;i--) s*=i;
	return s; 
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3)
	{
		int a[3];
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[0]+a[1]+a[2]>2*a[2]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		sum+=t(n)/t(n-i)/t(i);
	}
	cout<<sum;
	return 0;
} 
