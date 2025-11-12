#include<bits/stdc++.h>
using namespace std;

int main(){
	string b;
	char c[1000];
	int a;
	cin>>b;
	for(int i=0;i<=2;i++){
		if(b[i]>=48&&b[i]<=58){
			c[i]=b[i];
		}
		
	}
	for(int i=1;i<=50;i++){
		cout<<c[i];
	}
	return 0;
}
