#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int c[a];
	for (int i=0;i<a;i++){
		cin>>c[i];
		//cout<<c[i];
	}
	if(c[0]==b||c[a]==b){
		cout<<a-2;
	}
	if(c[1]==b||c[a-1]==b){
		cout<<"1";
	}
	return 0;
} 
