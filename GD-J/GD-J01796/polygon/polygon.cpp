#include<bits/stdc++.h>;
using namespace std;
long long ans=0,mod=998244353;
int n,a[5002];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=i+2;k<n;k++){
					if(a[i]+a[j]+a[k]>max(a[i],a[j],a[k])*2){
						ans++;
					}
					else{
						break;
					}
				}
			}
		}
		cout<<ans%mod;
		return 0;
	}
}
