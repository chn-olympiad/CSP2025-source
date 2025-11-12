#include <bits/stdc++.h>
using namespace std;
long long a,b[100000000],c;
int main(){
	
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
		if(b[i]=='1') cout<<"9";
		else if(b[i]=='2') cout<<"6";
	} 
	
	return 0;
}

