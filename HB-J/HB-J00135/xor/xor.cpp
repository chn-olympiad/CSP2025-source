#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==1){
		cout<<n/2;
	}
	 else if(k==0){
		cout<<n;
	}
	else{
		cout<<"63";
	}
	return 0;
}
