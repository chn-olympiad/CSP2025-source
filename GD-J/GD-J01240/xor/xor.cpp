#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		bool f=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]){
				if(f==0) f=1;
				else ans++,f=0;
			}else{
				if(f) f=0;
				ans++;
			}
		}
		cout<<ans;
	}else if(k==1){
		bool x1h0=0,x0h1=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i+2<=n){
				if(a[i]==a[i+1]&&a[i+1]==a[i+2]){
					ans++;
				}
			}
			if(a[i]){
				if(x0h1==1) ans++,x0h1=0,x1h0=1;
				else x1h0=1;
			}else{
				if(x1h0==1) ans++,x0h1=1,x1h0=0;
				else x0h1=1;
			}
		}
		cout<<ans;
	}
	return 0;
}
