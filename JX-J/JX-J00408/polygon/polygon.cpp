#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5555],s[5555],ans;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3)
	{
		if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1]) cout<<"1\n";
		else cout<<"0\n";
	}
	else
	{
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				if((s[j]-s[i-1])>(2*a[j]))
				{
					ans++;
					ans%=mod;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
