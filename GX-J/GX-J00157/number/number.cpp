#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	int b[a.sizeof()];
	for(int i=0;i<a.sizeof();i++){
		if(a[i]>=0&&a[i]<=9){
		b[i]=int(a[i]);
		}
	}
	for(int i=0;i<a.sizeof();i++){
		for(int j=i;j<a.sizeof();j++){
			if(b[j]>b[i]){
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=0;i<a.sizeof();i++){
		if(b[i]>=0&&b[i]<=9){
			cout<<b[i];
		}
	}
	return 0;
}
