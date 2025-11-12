#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans=0;
int a[5005];
int C[5005][5005];
int sum[5005];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],sum[i]=sum[i-1]+a[i];
		if(a[i]!=1)flag=0;
	}
	sort(a+1,a+n+1);
	if(n<=2){cout<<0;return 0;}
	if(n==3){cout<<(a[1]+a[2]>a[3]);return 0;}
	if(flag==1)
	{
		C[1][1]=C[1][0]=1;
		for(int i=2;i<=3000;i++)
			for(int j=0;j<=3000;j++)
			{
				if(j==0)C[i][j]=1;
				else C[i][j]=C[i-1][j]+C[i-1][j-1];
			}
		for(int i=1;i<=n;i++)
			for(int j=2;j<i;j++)ans=(ans+C[i-1][j])%mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
//		ans=0;
		vector<int> v;
		for(int j=1;j<i;j++)
		{
			v.push_back(a[j]);
			int len=v.size();
			for(int k=0;k<len-1;k++)v.push_back(v[k]+a[j]),ans=(ans+(v[k]+a[j]>a[i]))%mod;
		}
//		cout<<i<<" : \n";
//		for(int s:v)ans=(ans+(s>a[i]))%mod;//,cout<<s<<" ";
//		cout<<"\n";
//		cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
