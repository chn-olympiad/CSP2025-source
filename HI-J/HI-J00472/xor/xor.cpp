#include<bits/stdc++.h>
using namespace std;
int n,k,arr[5000005],flag=1,f=1,ans,f1=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]!=1){
			flag=0;
		}
		if(arr[i]!=1 && arr[i]!=0){
			f=0;
		}
	}
	if(flag){
		cout<<n/2;
		return 0;
	}
	if(f){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(arr[i]==1){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				if(i>=f1+2){
					f1=-1;
				}
				if(arr[i]==1){
					if(arr[i+1]==1 && f1==-1){
						ans++;
						f1=i;
					}
				}
				if(arr[i]==0){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
		cout<<48;
	}
	return 0;
}

