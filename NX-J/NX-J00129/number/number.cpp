#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream("number.in");
	ofstream("number.out");
	 int a[10001];
	 for(int i=0;i>=0;i++){
	 	cin>>a[i];
	 	if(a[i-1]>a[i]){
	 		a[i]=a[i-1];
	 	}
	 cout<<a[i];	                       
	 }
	 
	return 0;
}
