#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200000+10];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	int ans=0;
	if(k==1){
		for(int i=1; i<=n; i++){
			if(a[i]==k){
				ans++;
			} 
		}
	}else if(k==0){
		for(int i=1; i<=n; i++){
			if(a[i]==0){
				ans++;
			}else if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
		}
	}else{
		ans=0;
	}
	cout<<ans;
	return 0;
}
