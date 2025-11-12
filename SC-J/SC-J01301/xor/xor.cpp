#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500010];
	bool f=1;
	int w_0=0,w_1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
		if(a[i]==1) w_1++;
		if(a[i]==0) w_0++;
	} 
	if(f && k==0){//全是 1 
		cout<<n/2;
		return 0;
	}
	if(w_1+w_0==n && k==0){//B
		cout<<w_0+w_1/2;
		return 0;
	}
	if(w_1+w_0==n && k==1){//B
		cout<<min(w_1,w_0);
		return 0;
	}
	return 0;
}