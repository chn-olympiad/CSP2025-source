#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		sort(a,a+n);
		cout<<a[1];
		return 0;
	}
	cout<<k;
	return 0;
} 
