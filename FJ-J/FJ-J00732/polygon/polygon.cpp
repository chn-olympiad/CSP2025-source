#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005]={5005},cnt=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]>a[2]){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	for(int i=0;i<n;i++){
		if(a[i]+a[i+1]>a[i+2]){
			cnt++;
		}
		if(a[i]+a[i+1]+a[i+2]>a[i+3]){
			cnt++;
		}
		if(a[i]+a[i+1]+a[i+2]+a[i+3]>a[i+4]){
			cnt++;
		}
	}
	cout << cnt%998244353;
	return 0;
}
