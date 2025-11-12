#include<iostream>
#include<cstdio>
using namespace std;
int n,k,arr[500001],f1=1,f2=1,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]!=1) f1=0;
		if(arr[i]!=1 && arr[i]!=0) f2=0;
	}
	if(f1) cout<<n/2;
	else if(f2){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(arr[i]==0) ans++;
				else if(arr[i]==1 && arr[i+1]==1){
					ans++;
					i++;
				}
			}
			cout<<ans;
		}else{
			for(int i=1;i<=n;i++){
				if(arr[i]==1) ans++;
			}
			cout<<ans;
		}
	}
	return 0;
}
