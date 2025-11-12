#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==0){
		cout<<n/2;
	}
	else{
		cout<<(n-1)/2;
	}
	return 0;
} 
