#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5005],s[5005],maxn=-1,ans=0;
	cin>>n;
	for(int i=1;i<=n;++i){cin>>a[i];maxn=max(a[i],maxn);}
	if(maxn==1){
		for(int i=2;i<=n;++i){
			double s=1;
			for(int j=n;j>=n-i+1;--j){
				s*=j,s/=(j-i+1);
			}
			ans=ans%mod+s,ans%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)  s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			long long qsum=s[j]-s[i-1];
			if(qsum>a[j]*2) ans++;//连续区间
		}
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
