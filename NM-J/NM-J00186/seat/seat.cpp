#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	long long int a,b=1;
	cin>>a;
	for(long long int i=1;i<n*m;i++){
		long long int x;
		cin>>x;
		if(a<x){
			b+=1;
		}
	}
	if(b<n){
		cout<<1<<" "<<b;
	}else{
		if(b%n==0){
			if((b/n)%2==0){
				cout<<b/n<<" "<<1;
			}else{
				cout<<b/n<<" "<<n;
			}
		}else{
			cout<<(b/n)+1<<" ";
			if(((b/n)+1)%2==0){
				cout<<n-(b%n)+1;
			}else{
				cout<<b%n;
			}
		}
	}
	
	return 0;
} 
