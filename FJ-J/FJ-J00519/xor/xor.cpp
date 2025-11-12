#include<bits/stdc++.h>
using namespace std;
long long n,k,a,num_0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a;
		if(a==0){
			num_0++;
		}
	}
	if(k==0){
		cout<<num_0;
	}else{
		cout<<n-num_0;
	}
	return 0;
}
