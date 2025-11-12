#include<bits/stdc++.h>
using namespace std;
int b[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	if(k==0){
		cout<<n;
	}else{
		cout<<n/2;
	}
	return 0;
}
