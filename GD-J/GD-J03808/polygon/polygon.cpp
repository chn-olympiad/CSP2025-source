#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int mod=998244353;
int a[N],b[N];
int ans;
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=3;i<=n;i++)
	{
		if(b[i]>a[i]*2)ans++,ans%=mod;
		else continue;
		int num=i-3;
		while(num--)
		{
			for(int j=i-1;j>=num+1;j--)
			{
				if(b[j]-b[j-num-1]<b[i]-a[i]*2)
					ans++,ans%=mod;
			}
		}
	}
	cout<<ans%mod;
}
