#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			ans++;
		}
	}
	if(k==0 && !ans){
		cout<<n/2;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1] && a[i]==1){
				ans++;
				a[i]=0;
				a[i+1]=0;
			} 
		}
		cout<<ans;
	}
	else{
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		} 
		cout<<ans;
	}
	return 0;
} 
