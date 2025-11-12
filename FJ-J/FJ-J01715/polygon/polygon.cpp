#include<iostream>
using namespace std;
int ma(int a[],int n) {
	int m=0;
	for(int i=0; i<n; i++) {
		m=max(m,a[i]);
	}
	return m;
}
int he(int a[],int n) {
	int m=0;
	for(int i=0; i<n; i++) {
		m+=a[i];
	}
	return m;
}
void pin(int s,int a[],int n,int b[],int k,int gen,int &x) {
	int c[n]={};
	for(int i=0;i<n;i++){
		c[i]=b[i];
	}
	if(ma(c,n)*2<he(c,n) && gen>=3) {
		x++;
	}
	for(int i=s;i<n;i++){
		c[k]=a[i];
		pin(i+1,a,n,c,k+1,gen+1,x);
	}
}

int main() {
	int n,x=0;
	cin>>n;
	int a[n],b[n]= {};
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	int k=0,gen=1;
	for(int i=0; i<n; i++) {
		b[k]=a[i];
		pin(i+1,a,n,b,k+1,gen,x);
	}
	cout<<x%998244353;
	return 0;
}
