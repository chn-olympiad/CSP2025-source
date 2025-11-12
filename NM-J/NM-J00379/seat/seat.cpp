#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	long long n=0,m=0;
	cin>>n>>m;
	long long x[105]={};
	for(int i=0;i<n*m;i++){
		cin>>x[i];
	} 
	long long p=x[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m-1;j++){
			if(x[i+1]>x[i]){
				int a=x[i];
				x[i]=x[i+1];
				x[i+1]=a;
			}
		}
	}
	long long s=0;
	for(int i=0;i<n*m;i++){
		if(x[i]==p){
			s=i+1;
		}
	}
	cout<<s<<" ";
	if(s<=n){
		cout<<1<<" "<<s;
	}else{
		long long h=s/n;
//		if(h%n!=0){
//			cout<<h<<" "<<n-(s-h*n)+1;
//		}else{
//			cout<<h<<" "<<s-h*n;
//		}
		if(s%n==0){
			if(h%2==0){
				cout<<s/n-1<<" "<<1;	
			}else{
				cout<<h-1<<" "<<n;
			}
		
		}else{
			if(h%2==0){
				cout<<h+1<<" "<<s-h*n;
			}else{
				cout<<h+1<<" "<<n-(s-n*h)+1;
			}
			
			
			
		}
		
		
		
		
	}
	
	
	
	return 0;
}
