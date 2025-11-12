#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool x=true;
	bool y=true;
	int p=0,q=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) x=false;
		if(a[i]>1) y=false;
		if(a[i]==0) p++;
		if(a[i]==1) q++;
	}
	if(k==0){
		if(x==true){
			cout<<n-1;
		}
	}
	else if(k<=1){
		if(y==true){
			cout<<min(p,q)+1;
		}
	}
	return 0;
}