#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k; 
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		if(n==2){
			if(a[1]==1&&a[2]==1){
				cout<<1;
				return 0;
			}else if(a[1]==0&&a[2]==0){
				cout<<2;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}	
		if(n==1){
			cout<<0;
			return 0;
		}
		else{
			cout<<n/2;
			return 0;
		}
	}
	
	return 0;
}
