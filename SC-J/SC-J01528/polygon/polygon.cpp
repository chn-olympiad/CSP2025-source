#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,cnt,l,r,f=1,ans,a[5005],s[5005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f){
		if(n==3) ans=0;
		else if(n==4) ans=1;
		else if(n==5) ans=6;
		else{
			for(int i=1;i<=n-5;i++){
				ans+=((n-i+1)*(n-i)/2)%mod;
				ans%=mod;
			}
			ans=(ans+n+1)%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=3;i<=n;i++){
		if(s[i-1]<a[i]) continue;
		cnt=s[i-1]-a[i],r=l=i-1;
		for(int j=1;j<=i-1;j++){
			if(s[j]>=cnt){
				l=j-1;
				break;
			}
		}
		for(int j=l-1;j>=1;j--){
			ans+=((j+1)*j/2)%mod;
			ans%=mod;
		}
		for(int j=l+1;j<=i-1;j++){
			if(a[j]>=cnt){
				r=j-1;
				break;
			}
		}
		if(r==0){
			ans++;
			ans%=mod;
			continue;
		}
		else ans+=r,ans%=mod;
	}
	cout<<ans;
	return 0;
}
