#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,t;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
	}
	cout<<(n+3)*(n-3+1)/2;
	return 0;
}
