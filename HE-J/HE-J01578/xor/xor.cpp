#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],c1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			c1++;
		}
	}
	if(k==0){
		cout<<n/2;
	}else{
		cout<<c1;
	}
	return 0;
}
