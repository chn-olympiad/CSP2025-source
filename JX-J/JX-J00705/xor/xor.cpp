#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,jg0=0,a,jg1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(!a){
			jg0++;
		}else{
			jg1++;
		}
	}
	if(k==0){
		cout<<jg0;
	}else{
		cout<<jg1;
	}
	return 0;
}
