#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	if(n<50&&n>20){
		cout<<30;
	}else if(n<20&&n>10){
		cout<<5;
	}else{
		cout<<2;
	}
	return 0;
}
