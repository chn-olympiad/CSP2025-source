#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,k,a[N],x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	if(k==0){
		cout<<n/2;
	}
	if(k==1){
		cout<<a[1];
	}
	return 0;
}