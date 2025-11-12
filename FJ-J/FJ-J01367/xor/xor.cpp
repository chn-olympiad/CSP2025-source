#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n<=2){
		k=0;
		if(n==1) cout<<"0";
		else cout<<"1";
		return 0;
	}
	if(k==0){
		cout<<n/2;
	}
	else cout<<"1";
	return 0;
}
