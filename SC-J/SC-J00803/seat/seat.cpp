#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int b=n*m;
	int a[b+1];
	int c[b+1];
	int x,y=0;
	for(int i=1;i<=b;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	int d=a[1];
	for(int i=1;i<=b-1;i++){
		for(int j=i+1;j<=b;j++){
			if(a[i]>a[j]){
				a[i]=c[j];
				a[j]=c[i];
				c[i]=a[i];
				c[j]=a[j];
			}
		}
	}
	int e=0;
	for(int i=1;i<=b;i++){
		if(a[i]==d){
			e=b-i+1;
			break;
		}
	}
	if(e%n==0){
		x=e/n;
	}
	else{
		x=e/n+1;
	}
	if(x%2!=0){
		y=e%n;
		if(y==0){
			y=n;
		}
		else{
			y=e%n;
		}
	}
	else{
		y=n-e%n+1;
		if(y==0){
			y=1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}