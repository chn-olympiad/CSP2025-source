#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ling,yi,kl;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			ling++;
		}
		else if(a[i]==1){
			yi++;
		}
	}
	if(k==0){
		cout<<1;
	}
	return 0;
}
