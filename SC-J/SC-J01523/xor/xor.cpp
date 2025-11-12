#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool if1=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)if1=0;
	}
	if(if1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				ans++;
			}else{
				if(a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
		return 0;
	}else{
		for(int i=0;i<n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}