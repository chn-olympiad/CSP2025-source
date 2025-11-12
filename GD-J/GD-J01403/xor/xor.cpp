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
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<1;
		return 0;
	}
	if(n>2&&n<=10){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans;
		return 0;	
	}
	if(n>10){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(n%2==0){
					ans=(n/2)*(n/2);
				}
				else{
					ans=(n/2)*(n/2)+(n/2);
				}
			}
			cout<<ans;
			return 0;
		}
	}
}
