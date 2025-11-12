#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int m=size(s);
	int a[m],b[m];
	int c=0,n;
	for(int i=0;i<m;i++){
		b[i]=s[i];
	}
	for(int i=0;i<m;i++){
		if(b[i]>=48&&b[i]<=57){
			a[c]=b[i];
			c++;
		}
	}
	for(int i=0;i<=c;i++){
		for(int j=0;j<c;j++){
			if(a[j]>a[j+1]){
				n=a[j];
				a[j]=a[j+1];
				a[j+1]=n;
			}
		}
	}
	for(int i=c-1;i>=0;i--){
		cout<<a[i]-48;
	} 
}