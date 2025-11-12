#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
void q(int k,int ax,int sum){
	if(k>n) return;
	if(max(ax,a[k])*2<sum+a[k]&&k>=3){
		ans=(ans+1)%998244353;
	}
	q(k+1,max(ax,a[k]),sum+a[k]);
	q(k+1,ax,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	q(1,0,0);
	cout<<ans;
	return 0;
}
