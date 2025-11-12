#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long ans=0;
long long sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	if(n>3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					for(int h=1;h<=n;h++){
						if(i==h||j==h||k==h) continue;
						if((i+j+h>k&&k>i&&k>j&&k>h)||(i+j+k>h&&h>i&&h>j&&h>k)||(i+k+h>j&&i>j&&k>j&&h>j)||(j+k+h>i&&j>i&&k>i&&h>i)){
							ans++;
							ans%=mod;
						}
					}
				}
			}
		}
	}
	cout<<ans%mod;
	return 0;
}
