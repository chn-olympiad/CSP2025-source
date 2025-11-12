#include<bits/stdc++.h>
using namespace std;
int maxx=-0x3f3f3f3f;
int n;
const int K=10e7+1;
int a[K];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	int k;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int a1=0,a0=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			a1++;
		}else{
			a0++;
		}
	}
	if(k==1){
		if(a1%2==1){
			for(int i=n;i>=1;i--){
				if(1==a[i]){
					cout<<i<<endl;
					break;
				}
			}
		}else{
			int ans=0;
			for(int i=n;i>=1;i--){
				if(1==a[i]){
					ans=n-1;
				}
			}
			for(int i=ans;i>=1;i--){
				if(a[i]==1){
					cout<<i;
					break;
				}
			}
		}	
	}else{
		if(a1%2==1){
			for(int i=n;i>=1;i--){
				if(a[i]==1){
					cout<<i-1;
					break;
				}
			}
		}else{
			cout<<n;
		}
	}
	return 0;
} 
