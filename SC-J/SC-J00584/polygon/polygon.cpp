#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=998244353;
int a[10010];
int n,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	int mx=-1,aaa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		if(a[i]!=1){
			f=0;
		}
	}
	if(n<=3){
		if(n==1||n==2){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int z=j;z<=n;z++){
					if(i==j||z==j||z==i){
						continue;
					}
					if(a[i]+a[j]+a[z]>max({a[i],a[j],a[z]})*2){
						ans++;
						ans=ans%mod;
					}
				}
			}
		}
		cout<<ans%mod;
		return 0;
	}else if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int z=j;z<=n;z++){
					if(i==j||z==j||z==i){
						continue;
					}
					if(a[i]+a[j]+a[z]>max({a[i],a[j],a[z]})*2){
						ans++;
						ans=ans%mod;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int z=j;z<=n;z++){
					for(int k=z;k<=n;k++){
						if(i==j||j==k||k==z||i==z||i==k||j==z){
							continue;
						}
						if(a[i]+a[j]+a[z]+a[k]>max({a[i],a[j],a[z],a[k]})*2){
							ans++;
							ans=ans%mod;
						}
					}
				}
			}
		}
		cout<<ans%mod;
		return 0;
	}else if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int z=j;z<=n;z++){
					if(i==j||z==j||z==i){
						continue;
					}
					if(a[i]+a[j]+a[z]>max({a[i],a[j],a[z]})*2){
						ans++;
						ans=ans%mod;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int z=j;z<=n;z++){
					for(int k=z;k<=n;k++){
						if(i==j||j==k||k==z||i==z||i==k||j==z){
							continue;
						}
						if(a[i]+a[j]+a[z]+a[k]>max({a[i],a[j],a[z],a[k]})*2){
							ans++;
							ans=ans%mod;
						}
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>mx*2){
			ans++;
			ans=ans%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	return 0;
}
