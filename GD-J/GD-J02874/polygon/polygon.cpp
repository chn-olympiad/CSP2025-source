#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,maxn=-1;
	cin >> n;
	if(n==3){
		for(int i=0; i<n; i++){
			cin >> a[i];
			sum +=a[i];
			maxn=max(maxn,a[i]);
		}
		if(maxn*2<sum){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		cout << 0;
	}
	return 0;
}
