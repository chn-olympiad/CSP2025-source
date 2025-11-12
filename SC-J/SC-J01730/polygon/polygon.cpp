#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000000],sum=0,flg=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) flg=1;
		else flg=0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[3]>=a[1]+a[2]) cout<<0;
		else cout<<1;
		return 0;
	}
	if(flg==1) cout<<n-2;
	return 0;
}