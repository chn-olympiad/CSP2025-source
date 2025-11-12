#include<iostream>
using namespace std;
int s(int a[100],int d){
	int b[100]={0},c[100];
	int k=0;
	for(int i=0;i<100;i++){
		b[a[i]]++;
	}for(int i=0;i<100;i++){
		for(int j=0;j<b[i];j++){
			a[k]=i;
			k++;
		}
	}
	return a[d];
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[100],e[100];
	int n,m,c,r,t,z;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}t=a[0];
	for(int i=0;i<n*m;i++){
		a[i]=s(a,i);
	}
	for(int i=0;i<n*m;i++){
		if(t==a[i]){
			z=i;
			break;
		}
	}c=z/(n-1)-1;
	if(c%2)r=z%n;
	else r=n-z%n;
	cout<<c<<r;
}
