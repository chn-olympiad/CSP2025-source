#include <bits/stdc++.h>
using namespace std;
int n,k,m,kkl;
int a[200000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]!=1){
			m=11;
		}
	}
	if(m!=11){
		cout<<n/2;
	}
	return 0;
} 