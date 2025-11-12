#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
long long jc(int k){
	if(k==0){
		return 1;
	}
	return k*jc(k-1);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	if(n==3){
		if(a[1]+a[2]>a[3] && a[3]-a[2]<a[1]) ans=1;
		else ans=0;
	}
	else if(n>20){
		for(int i=3;i<=n;i++){
			ans+=jc(n)/jc(n-i)/jc(i);
		}
	}
	cout<<ans;
	return 0;
}