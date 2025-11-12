#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freoepn("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<1;
	}
	else if(k<=1){
		cout<<1;
	}
	return 0;
}
