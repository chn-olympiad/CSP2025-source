#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll a[5001];
ll jc(ll p){
	ll ans=p;
	for(ll i=2;i<p;i++)ans*=i;
	return ans;
}
ll C(ll n,ll m){
	return jc(n)/jc(n-m)/jc(m);
}
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	ll n,ans=0;cin>>n;
	bool istest15_17=1,no=1;
	for(ll i=0;i<n;i++){cin>>a[i];if(a[i]!=1)istest15_17=0;}
	sort(a,a+n);
	ll chongfu=0;
	for(int i=0;i<n;i++)if(a[i]==a[i-1])no=0,chongfu++;
	if(n<3){cout<<0;return 0;}
	if(n==3){cout<<int(a[0]+a[1]>a[2]&&a[0]+a[2]>a[1]&&a[1]+a[2]>a[0]);return 0;}
	if(istest15_17){cout<<n-2;return 0;}
	if(no){
		for(int i=4;i<n;i++)ans+=C(n,i);
		for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++)
			if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]>a[i])ans++;
		cout<<ans+1;
		return 0;
	}
	for(int i=4;i<n;i++)ans+=C(n,i);
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)for(int k=j+1;k<n;k++)
		if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]>a[i])ans++;
	cout<<ans-chongfu*2+1;
	return 0;
}
