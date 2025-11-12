#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n<=2){
		cout<<1;
		return 0;
	}
	if(k==0){
		cout<<1;
		return 0;
	}
	int max=-2e9;
	int l=1,r=1;
	for(int i=1;i<=n;i++){
		if(a[i]^0==k){
			max=(a[i]^0);
		}
		for(int j=1;j<=n;j++){
			if(a[l]^a[r]>max&&a[l]+a[r]==k){
				max=a[i]^a[r];
			}	
			l++;
		}
		r++;
	}
	cout<<max;
	return 0;
}
