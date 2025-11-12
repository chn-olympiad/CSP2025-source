#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon,in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}k=max(a[1],a[2]);
	k=max(k,a[3]);
	if(2*k<a[1]+a[2]+a[3]){
		cout<<1;
	}else{
		cout<<0;
	}
}