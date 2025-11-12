#include<iostream>
using namespace std;
int main(){
	string s,a;
	int b;
	cin>>s;
	for(int i=0;i<s.size;i++){
	if(s[i]<64||s[i]>90){
		a+=s[i];}
	}
	for(int i=0;i<a.size;i++){
		for(int j=0;j<a.size-1;j++){
			if(a[i]<=a[i+1]){
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;}
		}
	}
	cout<<a;
	return 0;
}
