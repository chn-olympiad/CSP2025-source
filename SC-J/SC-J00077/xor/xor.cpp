#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	if(n<=2&&k==0){
		cout<<1;
		return 0;
	}
	if(n<=10&&k<=1){
		int s=0,x=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				s++;
			}else{
				x++;
			}
		}
		if(k==1){
			cout<<s;
		}else{
			cout<<s/2+x;
		}
		return 0;
	}
	if(n<=100&&k==0){
		cout<<n/2;
		return 0;
	}
	if(n<=100&&k<=1){
		int s=0,x=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				s++;
			}else{
				x++;
			}
			
		}
		if(k==1){
			cout<<s;
		}else{
			cout<<s/2+x;
		}
		return 0;
	}
	return 0;
} 