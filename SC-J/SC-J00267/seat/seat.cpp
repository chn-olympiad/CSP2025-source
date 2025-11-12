#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,f;cin>>n>>m;
	int a[m*n+5]={};
	for(int i=0;i<m*n;i++){
		cin>>a[i];
		if(i==0){
			f=a[i];
		}
	}
	freopen("","seat.in",stdin);
	for(int i=0;i<m*n;i++){
		for(int j=0;j<m*n;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==f){
			f=i+1;
		}
	}if((f/n)%2==1&&(f%n==0)){
		cout<<f/n<<" "<<n;
	}else if((f/n)%2==0&&(f%n==0)){
		cout<<f/n<<" "<<1;
	}else if((f/n)%2==0&&(f%n!=0)){
		cout<<f/n+1<<" "<<f%n;
	}else{
		cout<<f/n+1<<" "<<n-f%n+1;
	}
	freopen("","seat.out",stdout);
	return 0;
}