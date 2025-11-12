#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int  n=0;
	int m=0;
	cin>>n>>m; 
	vector<long long >x;
	for(int i=0;i<(m*n);i++){
		cin>>x[i];
	}
	long long  u=n*m;
	int s=0;
	for(int i=0;i<u;i++){
		if(x[0]<x[i]){
			s++;
		}
	}
	int a=0;
	int b=0;
	while(true){
		a=s/n;
		b=s%n;
		if(a%2==0){
		b=n-b;
		break;
		}else if(a%2!=0){
		break;
		}
	}
	for(int i=0;i<x.size() ;i++){
		cout<<a<<b;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;

}
