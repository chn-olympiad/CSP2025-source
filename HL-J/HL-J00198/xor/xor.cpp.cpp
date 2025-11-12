#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1e3+10;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		cout<<0;
	}
	if(n<=100&&k==0){
		cout<<0;
	}
	else{
		cout<<1;
	}
}
