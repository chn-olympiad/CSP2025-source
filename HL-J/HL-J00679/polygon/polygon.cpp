#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,a[N],b[N],k;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		k=max(a[i],k);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>k*2) cout << 1;
		else cout << 0;
	}
	else{
		cout << (n+4)*(n-3)/2;
	}
}
