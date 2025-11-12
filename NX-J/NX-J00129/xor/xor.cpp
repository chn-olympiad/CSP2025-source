#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream cin("xor.in");
	ofstream cout("xor.out");
	int n,k,a[10001],b=1;
	cin>>n>>k;
	cin>>a[n];
	for(int i=0;i<=n;i++){
		if(a[n]>a[n-b])
		cout<<a[n];
		b++;
		}
		if(a[n]<a[n-b]){
			cout<<a[n-b];
		}
	
	return 0;
}
