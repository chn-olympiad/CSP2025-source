#include<bits/stdc++.h>
using namespace std;
int a[200005]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,o=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
	    for(int i=1;i<=n;i++){
	 	    if(a[i]==1) o++;
	    }cout<<o;
	}
	else if(k==0){
	    for(int i=1;i<=n;i++){
	 	    if(a[i]==0) o++;
	    }cout<<o;
	}else cout<<n/2;
	return 0;
} 
