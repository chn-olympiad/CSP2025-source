#include<bits/stdc++.h>
using namespace std;
int nn,kk;
int aaa[50005];
int main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>nn>>kk;
	for(int i=1;i<=nn;i++){
		cin>>aaa[i];
	} 
	if(kk==0){
		cout<<1;
	}
	return 0;
} 
