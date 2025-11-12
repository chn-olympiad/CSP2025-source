#include <bits/stdc++.h>
using namespace std;
int a[5005]; 
int n, ans;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if(n<=2) ans=0;
	if(n==3) {
		int maxa;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			maxa=max(maxa, a[i]);
		}
		if((a[1]+a[2]+a[3])>maxa*2)ans=1; 
	}
	printf("%d", ans); 
	return 0;
}
