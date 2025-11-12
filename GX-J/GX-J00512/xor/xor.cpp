#include<bits/stdc++.h>
using namespace std;
int a[200003];
int main(){
	int n,i,k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int ans=0;
		for(i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			else{
				if(a[i+1]==1 && i+1<=n){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(k==1){
		int ans=0;
		for(i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
}
