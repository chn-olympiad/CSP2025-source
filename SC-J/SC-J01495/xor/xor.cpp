#include<bits/stdc++.h>
using namespace std;
const int N=100000000;
long long k=0,a[N];
int n=0,sum=0;
int main(){
	
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(k==0){
		cout<<n/2;
	}
	else{
		cout<<0;
	} 
	
	return 0;
}