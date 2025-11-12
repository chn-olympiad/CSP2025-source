#include<bits/stdc++.h>
using namespace std;
int a[5010],n;
long long ans;
int jc(int n)
{
	if(n==1)return 1;
	return n*jc(n-1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		if(n==i)
		{
			ans+=1;
			ans%=998244353;
			break;
		}
		else ans=ans+jc(n)/(jc(i)*jc(n-i));
		ans%=998244353;
	}
	cout<<ans<<endl;
	return 0;
}

