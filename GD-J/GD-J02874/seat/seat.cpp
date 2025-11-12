#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int cnt;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
		if(i==1){
			cnt=a[i];
		}
	}
	sort(a+1,a+1+n*m);
	int sum;
	for(int i=n*m; i>=1; i--){
		if(a[i]==cnt){
			sum=n*m-i+1;
			break;
		}
	}
	int ans;
	if(sum%n==0){
		ans=sum/n;
	}else{
		ans=sum/n+1;
	}
	int x=sum%n;
	if(ans%2==0){
		if(x==0){
			cout << ans <<" "<< 1;
		}else{
			cout << ans <<" "<< n-x+1;
		}
	}else{
		if(x==0){
			cout << ans <<" "<< n;
		}else{
			cout << ans <<" "<< x;
		}
	}
	return 0;
}
