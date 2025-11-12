#include <bits/stdc++.h>
using namespace std;

int main(){
	int a;
	cin>>a;
	int b[a];
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	if(a<=2){
		cout<<"0";
	}
	if(a==3){
		if(b[0]+b[1]>b[2] & b[0]+b[2]>b[1] & b[1]+b[2]>b[0]){
			cout<<"1";
		}else{
			cout<<"0";
		}
	return 0;
}
