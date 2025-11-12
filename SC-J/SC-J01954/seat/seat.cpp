#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int k=1;
	for(int i=2;i<=m*n;i++){
		if(a[i]>a[1]){
			k++;
		}
	}
	int t=(k/(2*n)%2==0);
	if(((k-1)/n)%2==0){
		if(k%n==0){
			cout<<2*(k/t)+1<<" "<<n;
		}
		else{
			cout<<2*(k/t)+1<<" "<<k%n;
		}
	}	
	else{
		if(k%n==0){
			cout<<2*((k+n-1)/t)<<" "<<1;
		}
		else{
			cout<<2*((k+n-1)/t)<<" "<<n+1-k%n;
		}
	}
	return 0;
}