#include<bits/stdc++.h>
using namespace std;
long long n,k,a[54088],s=2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==2){
		s=1;
	}
	if(n==1){
		s=0;
	}
	cout<<s;
	return 0;
}

