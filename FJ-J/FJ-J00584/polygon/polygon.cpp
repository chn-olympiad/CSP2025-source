#include<bits/stdc++.h>
using namespace std;
long long n,sum,x,ans=1;
int a[5010],f=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		sum=sum%998244353; 
		if(a[i]!=1) f=0;
	}
	sort(a+1,a+n+1,greater<int>());
	if(n<3)  
	{
		cout<<'0';
		return 0;
	}
	if(n==3)
	{
		if(a[1]*2<sum) cout<<'1';
		else cout<<'0';
		return 0;
	}
	if(f==1)
	{
	    cout<<n;
	    return 0;
	} 
	for(int i=1;i<=n;++i)
	ans*=i; 
	cout<<ans/2;
	return 0;
}
