#include<bits/stdc++.h>
using namespace std;
int n,k,a[520315],xr[520315];
long long cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			xr[1]=a[i];
			continue;
		}
		xr[i]=(xr[i-1] xor a[i]);
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++)if((xr[i] xor xr[i-j])==k)cnt++;
	}
	cout<<cnt;
	return 0;
} 
