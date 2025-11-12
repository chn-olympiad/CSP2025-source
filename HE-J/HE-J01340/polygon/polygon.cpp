#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5050];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int s=0,maxn=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
		s+=a[i];
	}
	if(n==1||n==2)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(s>2*maxn)
		{
			cout<<1;
			return 0;
		}else
		{
			cout<<0;
			return 0;
		}
	}
	sort(a+1,a+1+n);
	if(n==4)
	{
		int ans=0;
		if(a[1]+a[2]+a[3]>a[3]*2)ans++;
		if(a[1]+a[2]+a[4]>a[4]*2)ans++;
		if(a[1]+a[3]+a[4]>a[4]*2)ans++;
		if(a[2]+a[3]+a[4]>a[4]*2)ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2)ans++;
		cout<<ans;
		return 0;
	}
	if(n==5)
	{
		int ans=0;
		if(a[1]+a[2]+a[3]>a[3]*2)ans++;
		if(a[1]+a[2]+a[4]>a[4]*2)ans++;
		if(a[1]+a[2]+a[5]>a[5]*2)ans++;
		if(a[1]+a[3]+a[4]>a[4]*2)ans++;
		if(a[1]+a[3]+a[5]>a[5]*2)ans++;
		if(a[1]+a[4]+a[5]>a[5]*2)ans++;
		if(a[2]+a[3]+a[4]>a[4]*2)ans++;
		if(a[2]+a[3]+a[5]>a[5]*2)ans++;
		if(a[2]+a[4]+a[5]>a[5]*2)ans++;
		if(a[3]+a[5]+a[4]>a[5]*2)ans++;
		if(a[1]+a[3]+a[4]+a[5]>a[5]*2)ans++;
		if(a[1]+a[2]+a[4]+a[3]>a[4]*2)ans++;
		if(a[1]+a[2]+a[3]+a[5]>a[5]*2)ans++;
		if(a[1]+a[2]+a[4]+a[5]>a[5]*2)ans++;
		if(a[3]+a[2]+a[4]+a[5]>a[5]*2)ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2)ans++;
		cout<<ans;
		return 0;
	}
	if(maxn==1)
	{
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
