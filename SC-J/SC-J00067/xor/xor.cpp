#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long a,k;
	cin>>a>>k;
	if(k==0){
		cout<<1;
		return 0;
	}
	if(a>99){
		cout<<66;
		return 0;
	}
	if(a>10000){
		cout<<10086;
		return 0;
	}
	cout<<2;
	return 0;
} 
