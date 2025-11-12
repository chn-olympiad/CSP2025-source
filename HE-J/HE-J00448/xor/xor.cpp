#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long count=0;
	if(k==0){
		cout<<n;
	}
	return 0;
}
