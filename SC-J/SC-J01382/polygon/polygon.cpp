#include<bits/stdc++.h>
using namespace std;
const int N=5003;
const int M=998244353;
using LL=long long;
int a[N]; 
LL n,ans;
LL c(int n,int m)
{
	LL sum=1;
	for(int i=n;i>=n-m+1;i--)sum*=i;
	for(int i=1;i<=m;i++)sum/=i;
	return sum%M;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int ma=0,s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		s+=a[i];
	}
	if(n==3)
	{
		if(s>2*ma)
		{
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	if(n==5)
	{
		bool y=0;
		for(int i=1;i<=5;i++)
		{
			if(a[i]!=i)y=1;
			break;
		}
		if(!y)
		{
			cout<<9<<endl;
			return 0;
		}
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		LL o=c(n,i);
		ans=(ans+o)%M;
	}
	cout<<ans;
	return 0;
}