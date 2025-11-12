#include<iostream>
#include<algorithm>
using namespace std;
int a[10005],n,ans=1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		
		ans*=i;
	}
    ans-=n;
    ans-=n;
    
	cout<<ans%998244353;
	return 0;
}
