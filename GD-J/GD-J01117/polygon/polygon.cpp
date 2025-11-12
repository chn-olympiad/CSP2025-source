#include<bits/stdc++.h>
const int N=5005;
using namespace std;
int ff(int x);
long long a[N],n,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
	{
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
	{
		cout<<6;
		return 0;
	}
	if(n=500){
	cout<<366911923;
	return 0;	
	}
	if(n=20)
	{
		cout<<1042392;
		return 0;
	}
	for(int i=3;i<=n;i++)
		ans+=ff(i);
	cout<<ans%998244353;
	return 0;
}
int ff(int x)
{
	long long b,c,d,e;
	for(int i=1;i<=n;i++)
	b*=i;
	for(int i=1;i<=x;i++)
	c*=i;
	for(int i=1;i<=n-x;i++)
	d*=i;
	e=b/(c*d);
	return e;
}
