#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			if(a[i]==1&&a[i-1]==1){
				ans++;
				if(i+1<=n){
					if(a[i+1]==0){
						ans++;
					}
				}
				if(i+2<=n)i=i+1;
				else break;
			}
		}
		cout<<ans;
	}
	else if(k==1){
	    for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}cout<<ans;
	}
	else {
	    for(int i=1;i<=n;i++){
			if(a[i]==k)ans++;
		}
		cout<<2*ans-1;
	}
    return 0;
}
