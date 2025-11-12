#include<bits/stdc++.h>
using namespace std;
long long n,a[6000],k=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) k=0;
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}else if(k==1){
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=2;
			ans%=998244353;
		}
		ans--;
		ans-=n;
		ans-=n*(n-1)/2;
		cout<<ans%998244353;
		return 0;
	}
	return 0;
}
