#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],a0,a1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d&d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(a[i]==0)a0++;
		if(a[i]==1)a1++;
	}
	if(k==0){
		cout<<a0;
	}
	if(k==1){
		cout<<a1+a0/2;
	}
	return 0;
}
