#include<iostream>
using namespace std;
int n,k,a[500005],most;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		most=0;
		for(int j=0;j<k;j++){
			most+=a[j];
		}
	}
	cout<<most;
	return 0;
}
