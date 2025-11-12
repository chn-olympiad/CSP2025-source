#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n; 
	for(int i = 1; i <= n; i++)
	cin >> a[i];
	sort(a+1, a+n+1);
	if(n<=2){
		ans = 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3])
		ans = 1;
		else
		ans = 0;
	}
	if(a[n]==1){
		ans = (n-2)*(n-1)/2;
	}
	cout << ans%998244353;
	return 0;
}