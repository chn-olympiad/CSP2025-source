#include<bits/stdc++.h>
using namespace std;
const int mod=996244353;
int n,a[5005];
bool ot=0;
int zh(int zs,int gs)
{
	long long ans=1;
	for(int i=zs,j=1;j<=gs;i--,j++)
	{
		ans*=i;
		ans%=mod;
	}
	for(int i=1;i<=gs;i++)
	{
		ans/=i;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)ot=1;
	}
	if(ot)
	{
		sort(a+1,a+1+n);
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<0;
		return 0;
	}
	long long ans=0;
	for(int i=3;i<=n;i++)
	{		
		ans+=zh(n,i);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
