#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int C(int a,int b)
{
	int t=1;
	for(int i=a-b+1;i<=a;i++) t*=i;
	for(int i=1;i<=b;i++) t/=i;
	return t;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==1||n==2) 
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a) cout<<1;
		else cout<<0;
		return 0;
	}
	int sum=0;
	for(int i=3;i<=n;i++)
	{
		sum+=C(n,i);
		sum%=mod;
	}
	cout<<sum;
	return 0;
} 
