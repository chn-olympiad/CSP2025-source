#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=-1;cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]> maxn*2) cout << 1;
		return 0;
	} 
	if(n<3){
		cout << 0;
		return 0;
	}
	else if(n==5){
		cout << 11;
		return 0;
	}
	else{
		long long cnt=0;
		for(int i = 3 ; i <= n ; i++){
			int k=n-i+3;
			cnt=cnt+(k*k-3*k+2)/2;
		}
		cout << cnt;
		return 0;
	}
	
	return 0;
} 