#include<iostream>
using namespace std;
void huo(int b[],int n,int k,int &x,int c[]) {
	int m=0;
	for(int i=0; i<n; i++) {
		if(b[i]==-1){
			break;
		}
		m=m^b[i];
	}
	if(m==k) {
		for(int i=0;i<n;i++){
			if(b[i]==-1){
				break;
			}
			c[i]=i+1;
		}
		x++;
	}
}
bool chong(int c[],int j,int n){
	for(int i=0;i<n;i++){
		if(c[i]==j){
			return 1;
		}
	}
	return 0;
}
void quan(int i,int n,int b[],int s,int a[],int k,int &x,int c[]) {
	if(chong(c,i,n)){
		return;
	}
	if(i==n){
		return;
	}
	huo(b,n,k,x,c);
	b[s]=a[i];
	quan(i+1,n,b,s+1,a,k,x,c);
}

int main() {
	int n,k;
	cin>>n>>k;
	int a[n],b[n]= {},c[n]={};
	for(int i=0;i<n;i++){
		b[i]=-1;
		c[i]=-1;
	}
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	int s=0,x=0;
	for(int i=0; i<n; i++) {
		b[s]=a[i];
		quan(i+1,n,b,s+1,a,k,x,c);
	}
	cout<<x;
	return 0;
}
