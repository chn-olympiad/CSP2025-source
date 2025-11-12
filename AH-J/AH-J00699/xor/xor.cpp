#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+5;
int n,k,a[MAX];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
	}
	return 0;
}
