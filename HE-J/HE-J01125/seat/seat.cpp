#include<iostream>
using namespace std;
int main(){
	int n,m,a[20000000],c,o,e,s;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	e=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]>a[j-1]){
				o=a[j];
				a[j]=a[j-1];
				a[j-1]=o;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==e){
			s=i+1;
		}
	}
	if(s<=n){
		c=1;
		cout<<1;
	}
	else{
		c=(s/n)+1;
		cout<<(s/n)+1;
	}
	cout<<" ";
	if(c%2==0){
		if(s%n==1){
			cout<<n;
		}
		else{
			cout<<n-(s%n);
		}
	}
	else{
		if(s%n==0){
			cout<<n;
		}
		else{
			cout<<s%n;
		}
	}
	return 0;
} 
