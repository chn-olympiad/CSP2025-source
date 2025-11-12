#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[10010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=2){
		cout<<0%998244353;
		return 0;
	}else if(n==3){
		if(a[1]+a[2]>a[n]&&a[1]+a[n]>a[2]&&a[2]+a[n]>a[1]&&a[n]-a[1]<a[2]&&a[n]-a[2]<a[1]&&a[2]-a[1]<a[n]&&a[1]+a[2]+a[3]>=a[3]*2){
			cout<<1%998244353;
			return 0;
		}else{
			cout<<0%998244353;
			return 0;
		}
	}
	return 0;
}
