#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5];
	for(int i=1;i<=n;i++) cin>>a[i];
	int p=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			p=1;
		}
	}
	int pp=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1 && a[i]!=0) pp=1;
	}
	if(p==0){
		cout<<n/2;
	}
	if(pp==0){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
			} 
			for(int i=1;i<=n;i++){
				if(a[i]==1) {
					int js=0;
					while (a[i]==1){
						i++;
						js++;
					}
					ans+=js/2;
				}
			}
			cout<<ans;
		}
		if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
		}
	}
}
