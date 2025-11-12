#include<bits/stdc++.h> 
using namespace std;
int main(){
	int a[101];
	int z,m,q,n,o,p;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m=a[0];
		for(int j=0;j<i-1;j++){
	if(a[j]<a[i]){
		z=a[i];
		a[i]=a[j];
		a[j]=z;
	}
}
	}
	for(int i=0;i<n;i++){
	if(a[i]==m) break;
		else q++;
	}
	o=q/4;
	p=q%4;
	if(p!=0) o++;
	if((o%2)==0) p=5-p;
	cout<<o<<" "<<p;
	return 0;
}
