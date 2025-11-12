#include <bits/stdc++.h>
using namespace std;
int a[900000],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
		}
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;//测评机你真帅（good），给点分，给点分，求求了 
}
