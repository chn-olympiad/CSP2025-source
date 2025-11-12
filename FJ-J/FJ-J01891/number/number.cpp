#include<iostream>
using namespace std;
string x,r;
int main(){
	cin>>x;
	for(int i=0;i<x.length();i++){
		if(x[i]<=10 && x[i]>=0){
			r+=x[i];
		}
	}
	
	for(int i=0;i<r.length();i++){
		for(int j=0;j<r.length();j++){
			if(r[j]<r[j+1]){
				swap(r[j],r[j+1]);
			}
		}
	}
	cout<<r;
	return 0;
}
