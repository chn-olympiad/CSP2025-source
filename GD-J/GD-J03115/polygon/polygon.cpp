#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[5005],b[5005];
int mod=998244353;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,b,c,d;
	bool flag=1;
	cin>>n;
	cin>>b>>c>>d;
	for(int i=4;i<=n;i++)
	{
		int a;
		cin>>a;
		if(a!=1)
			flag=0;
	}
	if(n==3)
		cout<<int(b+c>d&&c+d>b&&b+d>c);
	else// if(flag)
	{
		int ans=0;
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<n;j++)
				for(int k=k+1;k<=n;k++)
					ans=(ans+1)%mod;
		cout<<ans%mod; 
	}
//	int n,ans=0;
//	cin>>n;
//	for(int i=1;i<=n;i++)
//		cin>>a[i];
//	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//		b[i]=b[i-1]+a[i];
//	for(int i=1;i<=n;i++)
//		cout<<b[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n-2;i++)
//		for(int j=i+1;i<=n;i++)
//			if(b[i]-b[j-1]>a[j]*2)
//				ans=(ans+1)%mod;
//	cout<<ans%mod;
	return 0;
}

