#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,c,b,sum=0;
	cin>>a>>c;
	for(long long i=1;i<=a;i++){
		cin>>b;
		if(b==c){
			sum++;
		}
	}
	cout<<sum;
} 
