#include<bits/stdc++.h>
using namespace std;
int const mod=998244353;
long long ans=0,h=0,t=0;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		h=0;
		for(int j=i;j<=n;j++)
		{
			h=h+a[j];
			t=a[j]*2;
			if(h>t)ans++;
		}
	}
	ans=ans%mod;
	cout<<ans;
	return 0;
}
