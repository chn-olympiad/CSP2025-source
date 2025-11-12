#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0,vmax=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		vmax=max(a[i],vmax);
	}
	if(n==3){
		if(sum>2*vmax) cout<<1;
		else cout<<0;
	}
	else if(vmax<=1){
		int ans=(n-1)*(n-2)/2;
		cout<<ans;
	}
	return 0;
}
