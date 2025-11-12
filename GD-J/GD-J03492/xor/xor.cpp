#include<bits/stdc++.h>
using namespace std;
long long n,k,rt,t,sum,ans;
long long a[2222222];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) t++;
		rt=max(rt,a[i]);
	}
	if(n<1000){
		for(int i=1;i<=n;i++){
			sum=0;
			for(int u=i;u<=n;u++){
				sum=(sum^a[u]);
				if(sum==k){
					ans++;
					i=u;
					break;
				}
			}
		}
		return cout<<ans,0;
	}
	if(rt<=1){
		if(k==1) cout<<n-t;
		else cout<<(n-t)/2+t;
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum=0;
		for(int u=i;u<=n;u++){
			sum=(sum^a[u]);
			if(sum==k){
				ans++;
				i=u;
				break;
			}
		}
	}
	return cout<<ans,0;
}
