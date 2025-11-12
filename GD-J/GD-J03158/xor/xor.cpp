#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long n,k;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		if(n<=2){
			if(n==2){
				cout<<n;
			}else if(n==1){
				cout<<0;
			}
		}
		else{
			if(n%2==0){
				cout<<n;
			}else{
				cout<<n-1;
			}
		}
	}else if(k==1){
		int c1=0,c0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) c1++;
			if(a[i]==0) c0++; 
		}
		if(c1==0){
			cout<<0;
		}else if(c0==0){
			if(c1%2==0){
				cout<<n-1;
			}else{
				cout<<n;
			}
		}else if(c1==c0){
			if(c1%2!=0&&c0%2!=0){
				cout<<n;
			}else{
				cout<<n-1;
			}
		}else{
			if(c1>c0){
				if(c1%2!=0){
					cout<<n;
				}else{
					cout<<n-1;
				}
			}else if(c1<c0){
				if(c1%2!=0){
					cout<<n;
				}else{
					cout<<n-1;
				}
			}
		}
	}
	return 0;
} 
