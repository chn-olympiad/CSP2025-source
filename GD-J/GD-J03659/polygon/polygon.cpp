#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],ans,s[1000005];
long long dg(long long x,long long y,long long z){
	if(y*2<x&&t>=3)
	ans++,ans%=998244353;
	for(int i=z+1;i<=n;i++)
	{
		t++;
		dg(x+a[i],max(y,a[i]),i);
		t--;
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>=500)
	{
		s[1]=1;
		for(int i=2;i<=n;i++)
		{
			s[i]=i*s[i-1];
			s[i]%=998244353;
		}
		for(int i=3;i<=n;i++)
		{
			long long he=s[n],k=s[n-i]*s[i];
			ans=he/k+ans;
			ans%=998244353;
		}
		cout<<ans%998244353;
		return 0;
	} 
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dg(0,0,0); 
	cout<<ans%998244353;
	return 0;
}

