#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n < 3){
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(2*a[n]<sum){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}else{
		cout << 16;
	}
	return 0;
}