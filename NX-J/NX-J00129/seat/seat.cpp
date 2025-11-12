#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream cin("seat.in");
	ofstream cout("seat.out");
	int n,m,a,b[10001];
	cin>>n>>m;
	a=n*m;
	for(int i=0;i<=a;i++){
		cin>>b[a];
		if(b[a]>b[a-1]){
			m=n=1;
			cout<<m<<n;
		}else{
			m=n=2;
			cout<<m<<n;
		}
	}
	return 0;
	
}
