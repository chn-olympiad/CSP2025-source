#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	if(a[1]+a[2]>a[3]){
		cout<<1;
		return 0;
	}
	if(a[3]+a[2]>a[1]){
		cout<<1;
		return 0;
	}
	if(a[1]+a[3]>a[2]){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
