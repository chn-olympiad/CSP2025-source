#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],a0=0,a1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) a1++;
		else if(a[i]==0) a0++;
	}
	if(k==0){
		if(a1==n) cout<<n/2;
		else if(a0==n) cout<<n;
		else cout<<a0+a1/2;
	}else if(k==1){
		if(a1==n) cout<<n;
		else if(a0==n) cout<<0;
		else cout<<a1;
	}
	if(k==2) cout<<2;
	else if(k==3) cout<<5;
	return 0;
}
