#include<iostream>
#include<algorithm>
using namespace std;
int n,k,a[1000]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}else if(k<=1){
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]==k){
				ans++;
			}else{
				if(a[i+1]==a[i]){
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}else{
		int ans=0,i,x;
		if(a[0]==k){
			ans++;
			x=a[1];
			i=2;
		}else{
			x=a[0];
			i=1;
		}
		for(;i<n;i++){
			if(a[i]==k){
				ans++;
			}else{
				x^=a[i];
				if(x==k){
					ans++;
					x=a[i+1];
					i++;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

