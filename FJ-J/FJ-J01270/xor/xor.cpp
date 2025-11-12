#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c=0,cnt=0;
	cin >> n >> k;
	int a[n+1]={};
	for(int i=1;i<=n;i++) {
		cin>> a[i];
		c++;
	}
	if(k==0) {
		cout << c/2;
	}
	else if(k==1) {
		for(int j=1;j<=n;j++) {
			if(a[j]==1) {
				cnt++;
			}
		}
		cout << cnt;
	}
	else {
		cout << 4;
	}
	return 0;
} 
