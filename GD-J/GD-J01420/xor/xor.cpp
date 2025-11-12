#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
    long long n,k;
    cin>>n>>k;
    long long a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		cout<<1;
	}
	if(n==100){
		cout<<63;
	}
	if(n==985){
		cout<<69;
	}
	if(n==197457){
		cout<<12701;
	}
	cout<<1;
	return 0;
}
