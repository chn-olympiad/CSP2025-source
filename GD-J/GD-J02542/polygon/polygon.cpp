#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10010],s[10010],ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		//mx[i]=mx[i-1]+a[i];
	}
	for(int i=n;i>=3;i--)
	{
		for(int j=i-3;j>=0;j--)
		{
			if(a[i]*2<s[i]-s[j])
			{
				ans=ans+(j+1)*j/2+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
