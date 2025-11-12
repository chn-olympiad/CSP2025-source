#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[110],bh,zc,mod;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(long long i=n*m;i>=1;i--){
	    if(a[i]==r){
	    	bh=n*m-i+1;
		}
	}
	if(bh%n==0){
		zc=bh/n;
		mod=n;
	}else{
		zc=bh/n+1;
		mod=bh%n;
	}
	if(zc&1){
		cout<<zc<<" "<<mod<<endl;
	}else{
		cout<<zc<<" "<<n-mod+1<<endl;
	}
	return 0;
}
