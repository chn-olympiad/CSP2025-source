#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	unsigned long long maxx=1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]<=a[3]){
			cout<<0;
			return 0;
		}
		else {
			cout<<1;
			return 0;
		}
	}
	for(int i=n;i>=n-2;i--){
		for(int j=1;j<=n-2;j++){
			maxx=maxx*i%998244353;
		}
	}
	for(int i=1;i<=n-3;i++){
		for(int j=1;j<=i;j++){
			maxx=maxx*i%998244353;
		}
	}
	return 0;
}
