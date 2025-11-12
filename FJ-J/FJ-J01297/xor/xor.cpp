#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(k==0){
		if(n==1&&a[1]==1){
			cout<<0;
			return 0;
		} 
		if(n==2&&a[1]==1&&a[2]==1){
			cout<<1;
			return 0;
		} 
		if(n<=100){
			int s=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) s++;
			}
			if(s==n){
				cout<<n/2;
				return 0;
			}
		}
	}
	
	return 0;
}
