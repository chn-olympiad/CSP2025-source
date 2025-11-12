#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int ans=0;
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]&&i+1<=n){
				ans++;
				a[i]=a[i+1]=0;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]){
				ans++;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i]==a[i+1]&&i+1<=n){
				ans++;
				i++;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
		}
	}
	cout<<ans;
}
